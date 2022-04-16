import time
from random import randint, random
from math import inf


class Point:
    cnt = 0

    def __init__(self, x: float, y: float) -> None:
        self.x = x
        self.y = y

    def report(self):
        Point.cnt += 1
        # print(self.x, self.y)


class Rectangle:
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
    def intersect(a: Rectangle, b: Rectangle):
        return not (a.x1 > b.x2 or a.x2 < b.x1 or a.y1 > b.y2 or a.y2 < b.y1)

    @staticmethod
    def point_in_rec(a: Point, b: Rectangle):
        return b.x1 <= a.x <= b.x2 and b.y1 <= a.y <= b.y2

    @staticmethod
    def rec_in_rec(a: Rectangle, b: Rectangle):
        return b.x1 <= a.x1 <= a.x2 <= b.x2 and b.y1 <= a.y1 <= a.y2 <= b.y2


class Node:
    def __init__(self, n: int, points: list[Point], rec: Rectangle, split_x: bool) -> None:
        self.n = n
        self.points = points
        self.rec = rec
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

    def split_rectangle(self, med):
        if self.split_x:
            l_rec = Rectangle(self.rec.x1, med, self.rec.y1, self.rec.y2)
            r_rec = Rectangle(med, self.rec.x2, self.rec.y1, self.rec.y2)
        else:
            l_rec = Rectangle(self.rec.x1, self.rec.x2, self.rec.y1, med)
            r_rec = Rectangle(self.rec.x1, self.rec.x2, med, self.rec.y2)
        return l_rec, r_rec

    def report_all(self):
        for point in self.points:
            point.report()


class KD_tree:
    def __init__(self, n: int, points: list[Point]) -> None:
        self.root = self.__build(
            n, points, Rectangle(-inf, inf, -inf, inf), True)

    def __build(self, n: int, points: list[Point], rec: Rectangle, split_x: bool) -> Node:
        node = Node(n, points, rec, split_x)
        if node.n == 1:
            return node
        l_points, r_points, med = node.split_by_median()
        l_rec, r_rec = node.split_rectangle(med)
        node.l = self.__build(len(l_points), l_points, l_rec, not node.split_x)
        node.r = self.__build(len(r_points), r_points, r_rec, not node.split_x)
        return node

    def range_query(self, node: Node, query: Rectangle) -> list:
        if node is None:
            return
        if node.n == 1 and Util.point_in_rec(node.points[0], query):
            node.report_all()
        elif Util.rec_in_rec(node.rec, query):
            node.report_all()
        elif Util.intersect(node.rec, query):
            self.range_query(node.l, query)
            self.range_query(node.r, query)


if __name__ == '__main__':
    node_set = []
    num = 1000000
    for i in range(num):
        node_set.append(Point(random(), random()))
    kdtree = KD_tree(num, node_set)
    query = Rectangle(0.2, 0.4, 0.2, 0.4)

    t1 = time.time()
    kdtree.range_query(kdtree.root, query)
    t2 = time.time()

    t3 = time.time()
    bf_cnt = 0
    for point in node_set:
        if Util.point_in_rec(point, query):
            bf_cnt += 1
    t4 = time.time()

    if Point.cnt == bf_cnt:
        print('Correct!')
    else:
        print('Wrong answer!')
    print((t2 - t1) * 1000, (t4 - t3) * 1000)
