T = int(input())
for _ in range(T):
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    b0 = b[0]
    tot = 0
    ans = b[0] * a[0]
    for i in range(1, n):
        tot += a[i]
        b0 = min(b0, b[i])
        if tot > 0:
            ans += tot * b0
            tot = 0
    print('Case #%d: %d %d' % (_ + 1, b[0], ans))
