import heapq


class Heap:
    def __init__(self, data=[], key=None):
        self.key = key or (lambda x: x)

        self.idx = 0
        self.key_idx_heap = []
        self.data = {}

        for datum in data:
            self.push(datum)

    def push(self, value):
        self.idx += 1
        heapq.heappush(self.key_idx_heap, (self.key(value), self.idx))
        self.data[self.idx] = value

    def pop(self):
        _, idx = heapq.heappop(self.key_idx_heap)
        return self.data.pop(idx)

    def top(self):
        return self.data[self.key_idx_heap[0][1]]

    def __bool__(self):
        return bool(self.key_idx_heap)

    def __len__(self):
        return len(self.data)
