import sys


sys.stdout = open('test.out', 'w')


def read_file(path):
    items = []
    with open(path, 'r') as sys.stdin:
        while True:
            try:
                items.append(input().split())
            except EOFError:
                break
            for i in range(len(items)):
                items[i][3] = items[i][3].split('/')[-1]
    return items


get = read_file('SUSTech/ARP/get.txt')
no_get = read_file('SUSTech/ARP/no_get.txt')

res = []
for i in range(len(get)):
    if get[i] not in no_get:
        res.append(get[i])
print(*filter(lambda x: int(x[1]) < 10, res), sep='\n')

print('===========================================================')

res2 = []
for i in range(len(no_get)):
    if no_get[i] not in get:
        res2.append(no_get[i])
print(*filter(lambda x: int(x[1]) < 10, res2), sep='\n')
