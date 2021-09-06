class Solution:
    def slowestKey(self, releaseTimes: list[int], keysPressed: str) -> str:
        time, ans = releaseTimes[0], keysPressed[0]
        for i in range(1, len(releaseTimes)):
            ctime = releaseTimes[i] - releaseTimes[i-1]
            key = keysPressed[i]
            if ctime > time or (ctime == time and key > ans):
                time = ctime
                ans = key
        return ans
