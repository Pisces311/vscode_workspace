import sys
from random import randint

sys.stdout = open('SUSTech/CS203/2020Fall/Stone Game/Input/5.in', 'w')

T = 1000
print(T)
for cas in range(T):
    n = randint(1, 100)
    print(n)
    pile = [randint(1, 1e6) for i in range(n)]
    print(*pile)
