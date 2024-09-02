class Solution:
    def construct2DArray(self, org: List[int], m: int, n: int) -> List[List[int]]:
        if m*n != len(org):
            return []
        ans = [[0] * n for _ in range(m)]
        idx = 0
        for i in range(m):
            for j in range(n):
                ans[i][j] = org[idx]
                idx += 1
        return ans
