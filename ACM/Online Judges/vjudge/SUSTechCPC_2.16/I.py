a = [input() for i in range(3)]
for i in range(3):
    for j in range(10):
        if a[i][j] == '=':
            x, y = i, j
ob = '.'
for ch in a[x][y+1:]:
    if ch != '.':
        ob = ch
        break
if ob == '.':
    print('You shall pass!!!')
else:
    print(ob)
