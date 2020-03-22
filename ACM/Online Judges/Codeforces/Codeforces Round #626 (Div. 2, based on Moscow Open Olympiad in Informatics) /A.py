for case in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    odd = -1
    for i in range(n):
        if a[i] & 1 and odd == -1:
            odd = i
        elif a[i] & 1:
            print(2)
            print(odd + 1, i + 1)
            break
        else:
            print(1)
            print(i + 1)
            break
    else:
        print(-1)
