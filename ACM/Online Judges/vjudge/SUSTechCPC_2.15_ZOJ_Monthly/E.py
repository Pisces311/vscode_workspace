def less(K: int) -> int:
    ret = 0
    strK = str(K)
    lenK = len(strK)
    for i in range(lenK):
        ret += int(strK[:i+1]) - 10**i + 1
    return ret


T = int(input())
while T:
    T -= 1
    K, M = map(int, input().split())
    M -= less(K)
    if M < 0:
        print(0)
    elif M == 0:
        print(K)
    else:
        base = 10**(len(str(K))-1)
        high = K - base
        if base == K:
            print(0)
        else:
            base *= 10
            high *= 10
            while M > high:
                M -= high
                high *= 10
                base *= 10
            print(base + M - 1)
