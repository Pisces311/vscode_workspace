import sys
from random import randint

sys.stdout = open('SUSTech/CS203/2020Fall/XOR Fibonacci/Input/3.in', 'w')

T = 1000
print(T)
for cas in range(T):
    a, b, n = randint(0, 1e9), randint(0, 1e9), randint(0, 1e9)
    print(a, b, n)
