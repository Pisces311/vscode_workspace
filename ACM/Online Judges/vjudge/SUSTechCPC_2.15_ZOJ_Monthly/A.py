def f(x: int) -> int:
    cnt = 0
    while x:
        if x & 1:
            cnt += 1
        x >>= 1
    return cnt


t = int(input())
while t:
    t -= 1
    n = int(input())
    print(2**f(n-1))
