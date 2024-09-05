class Solution:
    def missingRolls(self, rolls: List[int], mean: int, n: int) -> List[int]:
        m = len(rolls)
        m_sum = sum(rolls)
        n_sum = mean * (m + n) - m_sum
        if n_sum / n > 6 or n_sum / n < 1:
            return []

        ans = [0] * n
        idx = 0
        while n_sum > 0:
            ans[idx] += 1
            n_sum -= 1
            idx = (idx+1) % n
        
        return ans