class Solution:
    def stoneGameII(self, piles: List[int]) -> int:
        n = len(piles)
        dp = {}
        def dfs(turn: bool, i: int, m: int) -> int:
            if i >= n:
                return 0
            if (turn, i, m) in dp:
                return dp[(turn, i, m)]

            ans = 0 if turn else float('inf')
            stones = 0 
            for x in range(1, 2*m + 1):
                if i+x-1 >= n:
                    break
                stones += piles[i+x-1]
                if turn:
                    ans = max(ans, stones + dfs(not turn, i+x, max(x, m)))
                else:
                    ans = min(ans, dfs(not turn, i+x, max(x,m)))
            
            dp[(turn, i, m)] = ans
            return ans
        
        return dfs(1, 0, 1)
