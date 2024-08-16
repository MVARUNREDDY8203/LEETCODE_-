class Solution {
public:
    vector<vector<int>> visited;
    void mark_island(int i, int j, vector<vector<int>> &grid) {
        if (i < 0 || i >= visited.size() || j < 0 || j >= visited[0].size() || grid[i][j] == 0 || visited[i][j] == 1) return;
        visited[i][j] = 1;
        mark_island(i+1, j, grid);
        mark_island(i-1, j, grid);
        mark_island(i, j+1, grid);
        mark_island(i, j-1, grid);
    }
    int count_islands(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size(), cnt = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) { 
                if (grid[i][j] == 1 && visited[i][j] == 0) {
                    mark_island(i, j, grid);
                    cnt++;
                }
            }
        }
        for (int i=0; i<m; i++) for (int j=0; j<n; j++) visited[i][j] = 0;
        return cnt;
    }
    int minDays(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

        int m = grid.size(), n = grid[0].size();
        visited.resize(m, vector<int>(n, 0));
        int island_cnt = count_islands(grid);
        if (island_cnt == 0 || island_cnt > 1) return 0;

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) {
                    grid[i][j] = 0;
                    int new_cnt = count_islands(grid);
                    if (new_cnt > 1 || new_cnt < 1) {
                        return 1;
                    }
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
    }
};