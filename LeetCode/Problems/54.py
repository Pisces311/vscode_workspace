class Solution:
    def spiralOrder(self, matrix: list[list[int]]) -> list[int]:
        n, m = len(matrix), len(matrix[0])
        used = [[False] * m for _ in range(n)]

        def inside(i, j):
            return 0 <= i < n and 0 <= j < m and not used[i][j]

        direction = ((0, 1), (1, 0), (0, -1), (-1, 0))
        ans = []
        x, y = 0, 0
        i = 0
        while len(ans) < n * m:
            ans.append(matrix[x][y])
            used[x][y] = True
            if (inside(x+direction[i][0], y+direction[i][1])):
                x += direction[i][0]
                y += direction[i][1]
            else:
                i = (i + 1) % 4
                x += direction[i][0]
                y += direction[i][1]
        return ans


a = Solution()
a.spiralOrder([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
