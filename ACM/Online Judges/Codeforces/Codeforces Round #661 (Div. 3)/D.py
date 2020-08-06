import queue

t = int(input())
while t:
    t -= 1
    n = int(input())
    s = input()
    q0, q1 = queue.Queue(), queue.Queue()
    belong = [0 for i in range(n)]
    tot = 0
    for i in range(n):
        if s[i] == '0':
            if not q1.empty():
                f = q1.get()
                belong[i] = f
                q0.put(f)
            else:
                tot += 1
                belong[i] = tot
                q0.put(tot)
        else:
            if not q0.empty():
                f = q0.get()
                belong[i] = f
                q1.put(f)
            else:
                tot += 1
                belong[i] = tot
                q1.put(tot)
    print(tot)
    print(*belong)
