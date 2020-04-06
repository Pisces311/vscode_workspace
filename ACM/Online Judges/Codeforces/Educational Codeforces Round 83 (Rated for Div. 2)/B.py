for case in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort(reverse=True)
    print(*a)
