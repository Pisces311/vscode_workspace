import sys

sys.stdin = open('input.txt', 'r')
sys.stdout = open('output.txt', 'w')

n = int(input())
a = [0] * 15
a[1] = 8
for i in range(2, 10):
    a[i] = a[i - 1] * 9
if n < 10:
    print(a[n])
else:
    print(a[9], end='')
    for i in range(10, n + 1):
        print(0, end='')
    print()
