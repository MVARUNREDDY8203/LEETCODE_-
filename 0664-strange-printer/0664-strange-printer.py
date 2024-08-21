class Solution:
    def strangePrinter(self, s: str) -> int:
        n = len(s)
        dp = {}
        def util(l: int, r: int) -> int:
            if l >= r:
                return 1
            if (l, r) in dp: 
                return dp[(l, r)]

            ans = float('inf')
            for k in range(l, r):
                ans = min(ans, util(l, k) + util(k+1, r))
            
            dp[(l, r)] = ans - 1 if s[l] == s[r] else ans
            return dp[(l, r)]
        
        return util(0, n-1)