class Solution:
    def isValidSudoku(self, board: list[list[str]]) -> bool:
        for i in range(9):
            nums = set()
            for j in range(9):
                if board[i][j] != '.' and board[i][j] in nums:
                    return False
                nums.add(board[i][j])
        for i in range(9):
            nums = set()
            for j in range(9):
                if board[j][i] != '.' and board[j][i] in nums:
                    return False
                nums.add(board[j][i])
        start = ((0, 0), (0, 3), (0, 6), (3, 0),
                 (3, 3), (3, 6), (6, 0), (6, 3), (6, 6))
        for x, y in start:
            nums = set()
            for i in range(3):
                for j in range(3):
                    dx, dy = x + i, y + j
                    if board[dx][dy] != '.' and board[dx][dy] in nums:
                        return False
                    nums.add(board[dx][dy])
        return True
