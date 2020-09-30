COLOR_BLACK = -1
COLOR_WHITE = 1
COLOR_NONE = 0

dx = [1, 1, 0, -1, -1, -1, 0, 1]
dy = [0, -1, -1, -1, 0, 1, 1, 1]


class AI:

    def __init__(self, size, color, time_out):
        self.size = size
        self.color = color
        self.time_out = time_out
        self.candidate_list = []
        self.values = []

    def __test(self, x, y, chessboard):
        corners = [(0, 0), (0, self.size - 1), (self.size - 1, 0),
                   (self.size - 1, self.size - 1)]
        Position_checker.set_piece(x, y, self.color, chessboard)
        for i, j in corners:
            if Position_checker.selectable(i, j, self.size, chessboard, -1 * self.color):
                Position_checker.set_piece(x, y, COLOR_NONE, chessboard)
                return False
        Position_checker.set_piece(x, y, COLOR_NONE, chessboard)
        return True

    def __find_valid_pos(self, chessboard):
        for x in range(self.size):
            for y in range(self.size):
                val = Position_checker.selectable(
                    x, y, self.size, chessboard, self.color)
                if val:
                    self.candidate_list.append((x, y))
                    if not self.__test(x, y, chessboard):
                        val = 0
                    self.values.append(val)

    def __select(self, idx):
        self.candidate_list[idx], self.candidate_list[-1] = \
            self.candidate_list[-1], self.candidate_list[idx]

    def __play(self, chessboard):
        if not self.candidate_list:
            return

        n = len(self.candidate_list)
        for i in range(n):
            if Position_checker.is_corner(*self.candidate_list[i], self.size):
                self.__select(i)
                return

        for i in range(n):
            if Position_checker.is_edge(*self.candidate_list[i], self.size) and self.values[i]:
                self.__select(i)
                return

        max_val = max(self.values)
        for i in range(n):
            if self.values[i] == max_val:
                self.__select(i)
                return

    def go(self, chessboard):
        self.candidate_list.clear()
        self.__find_valid_pos(chessboard)
        self.__play(chessboard)


class Position_checker:

    @staticmethod
    def set_piece(x: int, y: int, color: int, chessboard) -> None:
        chessboard[x][y] = color

    @staticmethod
    def is_corner(x: int, y: int, size: int) -> bool:
        corners = [(0, 0), (0, size - 1), (size - 1, 0), (size - 1, size - 1)]
        return (x, y) in corners

    @staticmethod
    def is_edge(x: int, y: int, size: int) -> bool:
        bounds = [0, size - 1]
        return x in bounds or y in bounds

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

        ret = 0
        for i, j in zip(dx, dy):
            px, py = x + i, y + j
            cnt = 0
            while Position_checker.is_piece(px, py, size, chessboard, color * -1):
                px, py = px + i, py + j
                cnt += 1
            if cnt and Position_checker.is_piece(px, py, size, chessboard, color):
                ret += cnt
        return ret
