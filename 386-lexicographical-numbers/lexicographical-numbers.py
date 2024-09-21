class Solution:
    def lexicalOrder(self, n: int) -> List[int]:
        res = []
        def dfs(a : int):
            if a > n:
                return
            res.append(a)
            dfs(a*10)
            if ((a+1)%10 != 0):
                dfs(a+1)
        dfs(1)
        return res