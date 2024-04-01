class Solution {
private:
    int m;
    int n;
public:
    int util(int i, int j, vector<vector<int>>&grid) {
        if (i < 0 || j < 0 || i >= m || j >= n) return 0;
        int ans = 0;
        if (grid[i][j] == 1) {
            grid[i][j] = 2;
            ans += util(i+1, j, grid);
            ans += util(i-1, j, grid);
            ans += util(i, j+1, grid);
            ans += util(i, j-1, grid);
            return ans + 1;
        }
        return 0;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);
        m = grid.size(), n = grid[0].size();
        int max_area = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) max_area = max(max_area, util(i, j, grid));
            }
        }
        return max_area;
    }
};