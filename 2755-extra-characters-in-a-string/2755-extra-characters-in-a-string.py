class Solution:
    def minExtraChar(self, s: str, dictionary: List[str]) -> int:
        dict = set(dictionary)
        n = len(s)
        dp = [-1] * (n + 1)

        def util(i: int) -> int:
            if (i >= n):
                return 0
            if (dp[i] != -1):
                return dp[i]
            
            not_take = 1 + util(i+1)
            take = float('inf')
            for j in range(i, n):
                curr = s[i:j+1]
                if curr in dict:
                    take = min(take, util(j+1))
            
            dp[i] = min(take, not_take)
            return dp[i]
        
        return util(0)


