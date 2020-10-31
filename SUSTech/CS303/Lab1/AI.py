COLOR_BLACK = -1
COLOR_WHITE = 1
COLOR_NONE = 0

dx = [1, 1, 0, -1, -1, -1, 0, 1]
dy = [0, -1, -1, -1, 0, 1, 1, 1]


weight = [[9, 2, 8, 7, 7, 8, 2, 9],
          [2, 1, 3, 4, 4, 3, 1, 2],
          [8, 3, 6, 5, 5, 6, 3, 8],
          [7, 4, 5, 4, 4, 5, 4, 7],
          [7, 4, 5, 4, 4, 5, 4, 7],
          [8, 3, 6, 5, 5, 6, 3, 8],
          [2, 1, 3, 4, 4, 3, 1, 2],
          [9, 2, 8, 7, 7, 8, 2, 9]]


class AI:

    def __init__(self, size, color, time_out):
        self.size = size
        self.color = color
        self.time_out = time_out
        self.candidate_list = []

    def __find_valid_pos(self, chessboard):
        for x in range(self.size):
            for y in range(self.size):
                if Position_checker.selectable(
                        x, y, self.size, chessboard, self.color):
                    self.candidate_list.append((x, y))

    def __play(self, chessboard):
        if not self.candidate_list:
            return
        self.candidate_list.sort(
            key=lambda x: (weight[x[0]][x[1]], Position_checker.test(
                x[0], x[1], self.size, chessboard, self.color)), reverse=True)

    def go(self, chessboard):
        self.candidate_list.clear()
        self.__find_valid_pos(chessboard)
        self.__play(chessboard)


class Position_checker:

    @staticmethod
    def test(x: int, y: int, size: int, chessboard, color: int):
        tot = 0
        for i, j in zip(dx, dy):
            px, py = x + i, y + j
            cnt = 0
            while Position_checker.is_piece(px, py, size, chessboard, color * -1):
                px, py = px + i, py + j
                cnt += 1
            if cnt and Position_checker.is_piece(px, py, size, chessboard, color):
                tot += cnt
        return tot

    @staticmethod
    def valid(x: int, y: int, size: int) -> bool:
        return x in range(size) and y in range(size)

    @staticmethod
    def is_piece(x: int, y: int, size: int, chessboard, color: int) -> bool:
        return Position_checker.valid(x, y, size) \
            and chessboard[x][y] == color

    @staticmethod
    def selectable(x: int, y: int, size: int, chessboard, color: int) -> int:
        if chessboard[x][y] != COLOR_NONE:
            return False

        for i, j in zip(dx, dy):
            px, py = x + i, y + j
            cnt = 0
            while Position_checker.is_piece(px, py, size, chessboard, color * -1):
                px, py = px + i, py + j
                cnt += 1
            if cnt and Position_checker.is_piece(px, py, size, chessboard, color):
                return True
        return False
