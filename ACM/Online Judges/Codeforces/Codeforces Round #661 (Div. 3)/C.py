t = int(input())
while t:
    t -= 1
    n = int(input())
    w = map(int, input().split())
    cnt = [0 for i in range(n + 1)]
    for i in w:
        cnt[i] += 1
    ans = 0
    for s in range(2, 2 * n + 1):
        tot = 0
        for i in range(1, n + 1):
            j = s - i
            if n < j or j < 1 or j > i:
                continue
            if i == j:
                tot += cnt[i] // 2
            else:
                tot += min(cnt[i], cnt[j])
        ans = max(ans, tot)
    print(ans)
