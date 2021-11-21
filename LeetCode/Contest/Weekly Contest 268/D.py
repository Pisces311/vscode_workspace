class Solution:
    def kMirror(self, k: int, n: int) -> int:
        lst = []
        numlst = [0]
        prev, cur = 1, 1
        while True:
            numlst[0] += 1
            p = 0
            while numlst[p] == k:
                numlst[p] = 0
                if p == len(numlst) - 1:
                    numlst.append(1)
                else:
                    numlst[p + 1] += 1
                p += 1
            cur = len(numlst)
            if cur != prev and len(lst) >= n:
                break
            prev = cur
            numStr = ''.join(map(str, numlst))
            x = int(numStr[::-1] + numStr, k)
            y = int(numStr[:0:-1] + numStr, k)
            if str(x) == str(x)[::-1]:
                lst.append(x)
            if str(y) == str(y)[::-1]:
                lst.append(y)
        lst.sort()
        return sum(lst[:n])
