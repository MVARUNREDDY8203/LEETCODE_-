class Solution:
    def findKthNumber(self, n: int, k: int) -> int:
        curr = ith_step = 1

        def cnt(curr: int) -> int:
            res = 0
            nei = curr + 1
            while curr <= n:
                nei = min(nei, n+1)
                res += nei - curr
                nei *= 10
                curr *= 10
            return res
        
        while ith_step < k: 
            steps = cnt(curr)
            if ith_step + steps <= k:
                ith_step += steps
                curr  += 1
            else:
                ith_step += 1
                curr *= 10
        
        return curr