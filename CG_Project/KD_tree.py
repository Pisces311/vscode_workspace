import time
from random import randint, random, uniform
import argparse
from matplotlib import pyplot as plt


class Point:
    cnt = 0

    def __init__(self, x: float, y: float) -> None:
        self.x = x
        self.y = y
        self.inside = False

    def report(self) -> None:
        Point.cnt += 1
        self.inside = True


class Range:
    def __init__(self, x1: float, x2: float, y1: float, y2: float) -> None:
        self.x1 = x1
        self.x2 = x2
        self.y1 = y1
        self.y2 = y2
        self.width = x2 - x1
        self.height = y2 - y1


class Util:
    @staticmethod
    def find_kth(a: list, l: int, r: int, k: int) -> float:
        """
        Find the kth smallest element in an array in O(n) time using divide and conquer.
        Similar idea can be found in quick sort.
        Ensure the construction time of KD tree is O(nlogn).
        """
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
            # In this case, a[lp] is the target
            return a[lp]
        elif n < k:
            # The target is on the right side
            return Util.find_kth(a, lp + 1, r, k - n)
        else:
            # The target is on the left side
            return Util.find_kth(a, l, lp, k)

    @staticmethod
    def intersect(a: Range, b: Range) -> bool:
        """
        Check if two rectangles intersect.
        """
        return not (a.x1 > b.x2 or a.x2 < b.x1 or a.y1 > b.y2 or a.y2 < b.y1)

    @staticmethod
    def point_in_rng(a: Point, b: Range) -> bool:
        """
        Check if the point is inside the rectangle.
        """
        return b.x1 <= a.x <= b.x2 and b.y1 <= a.y <= b.y2

    @staticmethod
    def rng_in_rng(a: Range, b: Range) -> bool:
        """
        Check if one rectangle is totally covered by the other.
        """
        return b.x1 <= a.x1 <= a.x2 <= b.x2 and b.y1 <= a.y1 <= a.y2 <= b.y2


class Node:
    def __init__(self, n: int, points: list[Point], rng: Range, x: bool) -> None:
        self.n = n
        self.points = points
        self.rng = rng
        self.x = x
        self.l = None
        self.r = None

    def split_by_median(self) -> tuple:
        """
        Split all the points in the current node by either the x-median or the y-median
        into two sets.
        """
        val = [point.x if self.x else point.y for point in self.points]
        med = Util.find_kth(val, 0, self.n - 1, (self.n + 1) // 2)
        l, r = [], []
        for point in self.points:
            if (self.x and point.x <= med) or (not self.x and point.y <= med):
                l.append(point)
            else:
                r.append(point)
        return l, r, med

    def report_all(self):
        for point in self.points:
            point.report()


class KD_tree:
    def __init__(self, n: int, points: list[Point]) -> None:
        x = [point.x for point in points]
        y = [point.y for point in points]
        self.lines = []
        self.root = self.__build(n, points, Range(
            min(x) - 2, max(x) + 2, min(y) - 2, max(y) + 2), True)

    def __build(self, n: int, points: list[Point], rng: Range, x: bool) -> Node:
        node = Node(n, points, rng, x)
        if node.n == 1:
            return node

        # Split the points by the median valud in O(n) time
        lpoints, rpoints, med = node.split_by_median()

        # Split the rectanglge by the median value we just found
        if node.x:
            lrng = Range(node.rng.x1, med, node.rng.y1, node.rng.y2)
            rrng = Range(med, node.rng.x2, node.rng.y1, node.rng.y2)
            self.lines.append((True, med, node.rng.y1, node.rng.y2))
        else:
            lrng = Range(node.rng.x1, node.rng.x2, node.rng.y1, med)
            rrng = Range(node.rng.x1, node.rng.x2, med, node.rng.y2)
            self.lines.append((False, med, node.rng.x1, node.rng.x2))

        # Recursively build the left child and the right child
        node.l = self.__build(len(lpoints), lpoints, lrng, not node.x)
        node.r = self.__build(len(rpoints), rpoints, rrng, not node.x)
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


def test():
    """
    Check the correctness of the KD tree.
    Compare the answers obtained by KD tree and brute force.
    """
    points = []
    num = 100000
    for _ in range(num):
        points.append(Point(random(), random()))
    print('Randomly generated', num, 'points in (0,1)*(0,1).\n')

    kdtree = KD_tree(num, points)

    print('Count the points inside the query range: (0.2,0.4)*(0.2,0.4)...\n')
    query = Range(0.2, 0.4, 0.2, 0.4)

    ans = 0
    for point in points:
        if Util.point_in_rng(point, query):
            ans += 1
    print('By brute force:', ans)

    kdtree.range_query(kdtree.root, query)
    print('By KD-tree:', Point.cnt)

    print('-'*10)
    if Point.cnt == ans:
        print('Accepted!')
    else:
        print('Wrong answer!')


def demo(path):
    """
    Show the graphical output of the KD tree.
    Read inputs from the specified file.
    """
    with open(path, 'r') as file:
        n = int(file.readline())
        points = []
        for _ in range(n):
            points.append(Point(*map(float, file.readline().split())))

    # Construct KD tree and request query range from the user.
    kdtree = KD_tree(n, points)
    query = Range(
        *map(float, input('Please specify the query rectangle: ').split()))
    kdtree.range_query(kdtree.root, query)

    # Plot the query range.
    rect = plt.Rectangle((query.x1, query.y1), query.width, query.height,
                         alpha=0.1)
    fig, ax = plt.subplots()
    ax.add_patch(rect)

    # Plot all the points. The points inside the query range are blue while the others are red.
    for point in points:
        if point.inside:
            ax.plot(point.x, point.y, 'ro')
        else:
            ax.plot(point.x, point.y, 'bo')

    # Plot the lines within the KD tree.
    for line in kdtree.lines:
        if line[0]:
            ax.vlines(*line[1:])
        else:
            ax.hlines(*line[1:])

    plt.show()


def efficiency():
    """
    Test the efficiency of the KD tree we constructed.
    """
    xval, bf, tree = [], [], []

    # Generate random samples from 100 to 5000
    for n in range(100, 5001, 50):
        xval.append(n)
        points = [Point(random(), random()) for _ in range(n)]
        x, y = uniform(0, 0.9), uniform(0, 0.9)
        query = Range(x, x + 0.1, y, y + 0.1)

        # Record the time we need to respond a query using brute force
        t1 = time.time()
        cnt = 0
        for point in points:
            if Util.point_in_rng(point, query):
                cnt += 1
        t2 = time.time()
        bf.append((t2 - t1) * 1000)

        # Record the time we need to respond a query using KD tree
        kdtree = KD_tree(n, points)
        t3 = time.time()
        kdtree.range_query(kdtree.root, query)
        t4 = time.time()
        tree.append((t4 - t3) * 1000)

    # Draw the graph
    plt.xlabel('number of points')
    plt.ylabel('time consumed (ms)')
    plt.plot(xval, bf, label='brute force')
    plt.plot(xval, tree, label='KD-tree')
    plt.legend()
    plt.show()


if __name__ == '__main__':
    parser = argparse.ArgumentParser('KD tree demo')
    parser.add_argument('-m', '--mode', type=str,
                        required=True, help='specify the working mode')
    parser.add_argument('-p', '--path', type=str,
                        help='specify the path to the input file')
    args = parser.parse_args()
    if args.mode == 'test':
        test()
    elif args.mode == 'demo':
        if args.path is None:
            print('The path to the input file must be specified.')
        else:
            demo(args.path)
    elif args.mode == 'efficiency':
        efficiency()
