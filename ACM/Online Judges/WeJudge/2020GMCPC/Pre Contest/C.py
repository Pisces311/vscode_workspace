while True:
    msg = input().split()
    if msg[0] == '#':
        break
    dic = {}
    for word in msg:
        dic[word] = 0
    for word in msg:
        dic[word] += 1
    size = len(msg)
    cnt = 0
    for _, i in dic.items():
        if i == 1:
            cnt += 1
    if cnt >= (size + 1) // 2:
        print('yes')
    else:
        print('no')
