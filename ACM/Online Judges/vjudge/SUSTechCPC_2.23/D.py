def parse_num(le, ri):
    ret = 0
    for i in range(le, ri):
        ret += (a[i] - 128) * 2**(7 * (i - le))
    ret += a[ri] * 2**(7 * (ri - le))
    if ret & 1:
        ret = -(ret + 1) // 2
    else:
        ret //= 2
    print(ret)


n = int(input())
a = list(map(int, input().split()))
le = 0
for i in range(n):
    if a[i] & (1 << 7) == 0:
        parse_num(le, i)
        le = i + 1
