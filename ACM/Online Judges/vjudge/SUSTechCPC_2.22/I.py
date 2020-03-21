import sys

sys.stdin = open('intel.in', 'r')
sys.stdout = open('intel.out', 'w')

n = int(input())
p = [list(map(int, input().split())) for i in range(n)]
tot = 0
le, ri, up, dn = p[0][0], p[0][0], p[0][1], p[0][1]
for i in range(1, n):
    tot += abs(p[i][0] - p[i - 1][0]) + abs(p[i][1] - p[i - 1][1])
    le = min(le, p[i][0])
    ri = max(ri, p[i][0])
    up = max(up, p[i][1])
    dn = min(dn, p[i][1])
tot += abs(p[0][0] - p[n - 1][0]) + abs(p[0][1] - p[n - 1][1])
rec = 2 * (ri - le + up - dn)
print(tot - rec)
