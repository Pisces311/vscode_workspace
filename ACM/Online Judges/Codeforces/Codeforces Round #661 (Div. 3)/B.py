t = int(input())
while t:
    t -= 1
    n = int(input())
    a = list(map(int, input().split()))
    b = list(map(int, input().split()))
    amin = min(a)
    bmin = min(b)
    ans = 0
    for i in range(n):
        opa = a[i] - amin
        opb = b[i] - bmin
        ans += max(opa, opb)
    print(ans)
