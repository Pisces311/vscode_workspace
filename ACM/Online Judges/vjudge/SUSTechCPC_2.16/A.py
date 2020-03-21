N, direction = input().split()
N = int(N)
a = [input() for i in range(N)]
dirR = {'^': '>', '>': 'v', 'v': '<', '<': '^', '.': '.'}
cnt = (sum(map(lambda i: 1 if i == 'R' else -1, direction)) + 200) % 4
if cnt == 1:
    for j in range(N):
        for i in range(N - 1, -1, -1):
            print(dirR[a[i][j]], end='')
        print()
elif cnt == 2:
    for i in range(N - 1, -1, -1):
        for j in range(N - 1, -1, -1):
            print(dirR[dirR[a[i][j]]], end='')
        print()
elif cnt == 3:
    for j in range(N - 1, -1, -1):
        for i in range(N):
            print(dirR[dirR[dirR[a[i][j]]]], end='')
        print()
else:
    for i in range(N):
        print(a[i])
