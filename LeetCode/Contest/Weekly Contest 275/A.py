class Solution:
    def checkValid(self, matrix: list[list[int]]) -> bool:
        n = len(matrix)
        for row in matrix:
            if n != len(set(row)):
                return False
        for j in range(n):
            col = set()
            for i in range(n):
                col.add(matrix[i][j])
            if n != len(col):
                return False
        return True
        