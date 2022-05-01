import time
from random import randint, random
from math import inf


class Point:
    cnt = 0

    def __init__(self, x: float, y: float) -> None:
        self.x = x
        self.y = y
        self.inside = False

    def report(self):
        Point.cnt += 1
        self.inside = True


class Range:
    def __init__(self, x1: float, x2: float, y1: float, y2: float):
        self.x1 = x1
        self.x2 = x2
        self.y1 = y1
        self.y2 = y2


class Util:
    @staticmethod
    def find_kth(a: list, l: int, r: int, k: int):
        pivot = randint(l, r)
        a[l], a[pivot] = a[pivot], a[l]
        lp, rp = l, r
        while lp != rp:
            while lp < rp and a[lp] <= a[rp]:
                rp -= 1
            a[lp], a[rp] = a[rp], a[lp]
            while lp < rp and a[lp] <= a[rp]:
                lp += 1
            a[lp], a[rp] = a[rp], a[lp]
        n = lp - l + 1
        if n == k:
            return a[lp]
        elif n < k:
            return Util.find_kth(a, lp + 1, r, k - n)
        else:
            return Util.find_kth(a, l, lp, k)

    @staticmethod
    def intersect(a: Range, b: Range):
        return not (a.x1 > b.x2 or a.x2 < b.x1 or a.y1 > b.y2 or a.y2 < b.y1)

    @staticmethod
    def point_in_rng(a: Point, b: Range):
        return b.x1 <= a.x <= b.x2 and b.y1 <= a.y <= b.y2

    @staticmethod
    def rng_in_rng(a: Range, b: Range):
        return b.x1 <= a.x1 <= a.x2 <= b.x2 and b.y1 <= a.y1 <= a.y2 <= b.y2


class Node:
    def __init__(self, n: int, points: list[Point], rng: Range, split_x: bool) -> None:
        self.n = n
        self.points = points
        self.rng = rng
        self.split_x = split_x
        self.l = None
        self.r = None

    def split_by_median(self):
        val = [point.x if self.split_x else point.y for point in self.points]
        med = Util.find_kth(val, 0, self.n - 1, (self.n + 1) // 2)
        l, r = [], []
        for point in self.points:
            if (self.split_x and point.x <= med) or (not self.split_x and point.y <= med):
                l.append(point)
            else:
                r.append(point)
        return l, r, med

    def split_range(self, med):
        if self.split_x:
            return Range(self.rng.x1, med, self.rng.y1, self.rng.y2), Range(med, self.rng.x2, self.rng.y1, self.rng.y2)
        else:
            return Range(self.rng.x1, self.rng.x2, self.rng.y1, med), Range(self.rng.x1, self.rng.x2, med, self.rng.y2)

    def report_all(self):
        for point in self.points:
            point.report()


class KD_tree:
    def __init__(self, n: int, points: list[Point]) -> None:
        self.root = self.__build(n, points, Range(-inf, inf, -inf, inf), True)

    def __build(self, n: int, points: list[Point], rng: Range, split_x: bool) -> Node:
        node = Node(n, points, rng, split_x)
        if node.n == 1:
            return node
        l_points, r_points, med = node.split_by_median()
        l_rng, r_rng = node.split_range(med)
        node.l = self.__build(len(l_points), l_points, l_rng, not node.split_x)
        node.r = self.__build(len(r_points), r_points, r_rng, not node.split_x)
        return node

    def range_query(self, node: Node, query: Range) -> list:
        if node is None:
            return
        if node.n == 1 and Util.point_in_rng(node.points[0], query):
            node.report_all()
        elif Util.rng_in_rng(node.rng, query):
            node.report_all()
        elif Util.intersect(node.rng, query):
            self.range_query(node.l, query)
            self.range_query(node.r, query)


if __name__ == '__main__':
    node_set = []
    num = 1000000
    for i in range(num):
        node_set.append(Point(random(), random()))
    kdtree = KD_tree(num, node_set)
    query = Range(0.2, 0.4, 0.2, 0.4)

    t1 = time.time()
    kdtree.range_query(kdtree.root, query)
    t2 = time.time()

    t3 = time.time()
    bf_cnt = 0
    for point in node_set:
        if Util.point_in_rng(point, query):
            bf_cnt += 1
    t4 = time.time()

    if Point.cnt == bf_cnt:
        print('Corrngt!')
    else:
        print('Wrong answer!')
    print((t2 - t1) * 1000, (t4 - t3) * 1000)
