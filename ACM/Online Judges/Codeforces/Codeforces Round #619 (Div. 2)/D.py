ans = [0]


def insert(x: int, y: str):
    global ans
    ans[0] += 1
    ans.append(x)
    ans.append(y)


n, m, k = map(int, input().split())
if k > 4*n*m-2*n-2*m:
    print('NO')
else:
    print('YES')
    if m == 1:
        if k <= n-1:
            insert(k, 'D')
        else:
            insert(n-1, 'D')
            insert(k-(n-1), 'U')
    else:
        if k <= m-1:
            insert(k, 'R')
        elif k <= 2*(m-1):
            insert(m-1, 'R')
            insert(k-(m-1), 'L')
        else:
            k -= 2*(m-1)
            insert(m-1, 'R')
            insert(m-1, 'L')
            level = k // (1+4*(m-1))
            if level <= n-1:
                for i in range(level):
                    insert(1, 'D')
                    insert(m-1, 'RUD')
                    insert(m-1, 'L')
                k -= level*(1+4*(m-1))
                if level == n-1:
                    if k > 0:
                        insert(k, 'U')
                else:
                    if k > 0:
                        k -= 1
                        insert(1, 'D')
                    if k > 0:
                        if k <= 3*(m-1):
                            times = k // 3
                            k -= times * 3
                            if times:
                                insert(times, 'RUD')
                            if k == 1:
                                insert(1, 'R')
                            elif k == 2:
                                insert(1, 'RU')
                            elif k == 3:
                                insert(1, 'RUD')
                        else:
                            k -= 3*(m-1)
                            insert(m-1, 'RUD')
                            insert(k, 'L')
            else:
                for i in range(n-1):
                    insert(1, 'D')
                    insert(m-1, 'RUD')
                    insert(m-1, 'L')
                k -= (n-1)*(1+4*(m-1))
                insert(k, 'L')
    print(ans[0])
    for i in range(1, len(ans), 2):
        print(ans[i], ans[i+1])
