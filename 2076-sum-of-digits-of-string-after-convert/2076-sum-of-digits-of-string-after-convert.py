class Solution:
    def getLucky(self, s: str, k: int) -> int:
        m = ""
        for i in s:
            m += str(ord(i) - ord('a') + 1)

        ans = 0
        while k > 0:
            ans = 0
            for digit in m:
                ans += int(digit)
            k -= 1
            m = str(ans)
        return ans
