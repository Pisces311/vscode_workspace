class Solution:
    def finalValueAfterOperations(self, operations: list[str]) -> int:
        x = 0
        for s in operations:
            if '+' in s:
                x += 1
            else:
                x -= 1
        return x