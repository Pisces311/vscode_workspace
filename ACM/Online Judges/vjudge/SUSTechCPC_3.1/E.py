n = int(input())
a = list(map(int, input().split()))
cnt = [0] * 1001
ans = []
every = 0
for i in range(n):
    if a[i] > 0:
        cnt[a[i]] += 1
    elif a[i] == 0:
        every += 1
    else:
        if cnt[-a[i]]:
            cnt[-a[i]] -= 1
        else:
            if every:
                ans.append(-a[i])
                every -= 1
            else:
                print('No')
                break
else:
    print('Yes')
    for i in range(every):
        ans.append(1)
    print(*ans)
