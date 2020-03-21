T = int(input())
while T:
    T -= 1
    n, g, b = map(int, input().split())
    if g >= b:
        print(n)
        continue
    limit = n // 2
    cycle = limit // b
    n -= cycle * (g + b)
    ans = cycle * (g + b)
    limit -= cycle * b
    ans += min(n, g)
    n -= min(n, g)
    if n:
        if n <= limit:
            ans += n
        else:
            n -= limit
            ans += b
            if n % g == 0:
                ans += (n // g - 1) * (b + g) + g
            else:
                ans += (n // g) * (b + g)
                n -= n // g * g
                ans += n
    print(ans)
