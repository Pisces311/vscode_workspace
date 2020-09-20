COLOR_BLACK = -1
COLOR_WHITE = 1
COLOR_NONE = 0


class AI:

    def __init__(self, chessboard_size, color, time_out):
        self.chessboard_size = chessboard_size
        self.color = color
        self.time_out = time_out
        self.candidate_list = []

    def find_valid_pos(self, chessboard):
        dx, dy = [1, 1, 0, -1, -1, -1, 0, 1], [0, -1, -1, -1, 0, 1, 1, 1]
        for row in range(self.chessboard_size):
            for col in range(self.chessboard_size):
                for i in range(8):
                    pass

    def go(self, chessboard):
        self.candidate_list.clear()
        self.find_valid_pos(chessboard)
