import sys
from random import randint

sys.stdout = open('SUSTech/CS203/2020Fall/Stone Game/Input/6.in', 'w')

T = 7
print(T)
for cas in range(T):
    n = randint(1, 1e5)
    print(n)
    pile = [randint(1, 1e6) for i in range(n)]
    print(*pile)
