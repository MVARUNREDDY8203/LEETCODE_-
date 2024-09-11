class Solution:
    def minBitFlips(self, start: int, goal: int) -> int:
        cnt = 0
        ans = start ^ goal
        while ans:
            cnt += (ans & 1)
            ans = ans >> 1
        
        return cnt