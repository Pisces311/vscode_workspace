import sys


def input(): return sys.stdin.readline().rstrip("\r\n")


for case in range(int(input())):
    a, b = map(int, input().split())
    dif = abs(a - b)
    if a > b:
        if dif & 1:
            print(2)
        else:
            print(1)
    elif a < b:
        if dif & 1:
            print(1)
        else:
            print(2)
    else:
        print(0)
