class Solution:
    def kthDistinct(self, arr: list[str], k: int) -> str:
        cnt = 0
        for i in arr:
            if arr.count(i) == 1:
                cnt += 1
                if cnt == k:
                    return i
        return ''
