import sys

sys.stdin = open('boolean.in', 'r')
sys.stdout = open('boolean.out', 'w')

s = [i.strip() for i in input().split('|')]
pos, neg = set(), set()
for i in s:
    sign = i[0] == '~'
    char = i[sign]
    neg.add(char) if sign else pos.add(char)
cnt = 0
for i in pos:
    if i in neg:
        cnt += 1
print(2**(len(pos) + len(neg) - cnt) - (cnt == 0))
