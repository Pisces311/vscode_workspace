def check():
    for i in range(1, n):
        if a[i] - a[i - 1] > 1:
            return False
    return True


t = int(input())
while t:
    t -= 1
    n = int(input())
    a = sorted(map(int, input().split()))
    if check():
        print('YES')
    else:
        print('NO')
