import sys
from random import randint

sys.stdout = open('SUSTech/CS203/2020Fall/Sum of Digits/Input/5.in', 'w')

T = 20000
print(T)
for cas in range(T):
    n, s = randint(1, 1e18), randint(1, 162)
    print(n, s)
