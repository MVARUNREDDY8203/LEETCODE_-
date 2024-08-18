class Solution:
    def isPossibleToCutPath(self, grid: List[List[int]]) -> bool:
        m, n = len(grid), len(grid[0])
        def dfs(i: int, j: int) -> bool:
            if i >= m or j >= n or grid[i][j] == 0:
                return False
            if i == m-1 and j == n-1:
                return True

            grid[i][j] = 0
            return dfs(i+1, j) or dfs(i, j+1)

        dfs(0,0)
        grid[0][0] = 1
        return not dfs(0,0)