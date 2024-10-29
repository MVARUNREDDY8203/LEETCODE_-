class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> g2(m, vector<int>(n, -1));
        function<int(int, int, int)> util = [&](int i, int j, int prev) -> int {
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] <= prev) return 0;

            if (g2[i][j] != -1) return g2[i][j];

            g2[i][j] = max(util(i-1, j+1, grid[i][j]), util(i+1, j+1, grid[i][j]));
            g2[i][j] = max(g2[i][j], util(i, j+1, grid[i][j]));
            g2[i][j] += 1;

            return g2[i][j];
        };

        int ans = 0;
        for (int i=0; i<m; i++) ans = max(ans, util(i, 0, -1));
        return ans-1;
    }
};