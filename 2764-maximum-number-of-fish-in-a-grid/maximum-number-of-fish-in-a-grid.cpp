class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0) return 0;

            int total_fish = grid[i][j];
            grid[i][j] = 0;

            total_fish += dfs(i+1, j);
            total_fish += dfs(i-1, j);
            total_fish += dfs(i, j+1);
            total_fish += dfs(i, j-1);

            return total_fish;
        };
        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j]) ans = max(ans, dfs(i, j));
            }
        }
        return ans;
    }
};