class Solution:
    def orderOfLargestPlusSign(self, n: int, mines: list[list[int]]) -> int:
        Map = [[1] * n for _ in range(n)]
        le = [[0] * n for _ in range(n)]
        ri = [[0] * n for _ in range(n)]
        up = [[0] * n for _ in range(n)]
        dn = [[0] * n for _ in range(n)]
        for i, j in mines:
            Map[i][j] = 0
        for i in range(n):
            for j in range(n):
                up[i][j] = le[i][j] = Map[i][j]
                if Map[i][j] == 1:
                    if i != 0:
                        up[i][j] += up[i-1][j]
                    if j != 0:
                        le[i][j] += le[i][j-1]
        for i in range(n - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                dn[i][j] = ri[i][j] = Map[i][j]
                if Map[i][j] == 1:
                    if i != n - 1:
                        dn[i][j] += dn[i+1][j]
                    if j != n - 1:
                        ri[i][j] += ri[i][j+1]
        k = 0
        for i in range(n):
            for j in range(n):
                k = max(k, min(up[i][j], dn[i][j], ri[i][j], le[i][j]))
        return k


sol = Solution()
print(sol.orderOfLargestPlusSign(2, [[0, 0], [0, 1], [1, 0]]))
