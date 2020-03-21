import sys

sys.stdin = open('anniversary.in', 'r')
sys.stdout = open('anniversary.out', 'w')

w, h, ax, ay, bx, by = map(int, input().split())

if ax != bx:
    if ax > bx:
        ax, ay, bx, by = bx, by, ax, ay
    if bx == ax + 1 and by == h:
        print(ax, h, ax + 1, 0)
    else:
        print(ax, 0, ax + 1, h)
else:
    if ay > by:
        ax, ay, bx, by = bx, by, ax, ay
    if by == ay + 1 and bx == w:
        print(0, ay + 1, w, ay)
    else:
        print(0, ay, w, ay + 1)
