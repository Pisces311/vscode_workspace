from collections import defaultdict
from string import ascii_uppercase


def alloc(var, obj):
    dic[var].add(obj)


def assign(var1, var2):
    dic[var1] |= dic[var2]


def store(var1, field, var2):
    for obj in dic[var1]:
        dic[obj + '.' + field] = dic[obj + '.' + field] | dic[var2]


def load(var1, var2, field):
    for obj in dic[var2]:
        dic[var1] = dic[var1] | dic[obj + '.' + field]


N = int(input())
a = []
dic = defaultdict(set)
for _ in range(N):
    a.append(input())
for _ in range(N):
    for line in a:
        s1, s2 = [x.strip() for x in line.split('=')]
        if s1.isupper() and s2.islower():
            alloc(s1, s2)
        if s1.isupper() and s2.isupper():
            assign(s1, s2)
        if '.' in s1:
            v, f = s1.split('.')
            store(v, f, s2)
        if '.' in s2:
            v, f = s2.split('.')
            load(s1, v, f)
for i in ascii_uppercase:
    print(i + ": " + "".join(sorted(list(dic[i]))))
