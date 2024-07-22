class Solution {
public:
    vector<vector<int>> grid2;
    queue<vector<int>> que;

    void dfs_marker(int i, int j, vector<vector<int>>&grid) {
        int m = grid.size(), n = grid[0].size();
        if (i >= m || j >= n || i < 0 || j < 0) return;

        if (grid[i][j] == 1) {
            grid[i][j] = -1;

            que.push({i+1, j, 1});
            que.push({i-1, j, 1});
            que.push({i, j+1, 1});
            que.push({i, j-1, 1});


            dfs_marker(i+1, j, grid);
            dfs_marker(i-1, j, grid);
            dfs_marker(i, j+1, grid);
            dfs_marker(i, j-1, grid);
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        grid2.resize(m, vector<int>(n, 0));

        for (int i=0; i<m; i++) {
            bool marked = 0;
            for (int j=0; j<n; j++) {
                if (grid[i][j]) {
                    dfs_marker(i, j, grid);
                    marked = 1;
                    break;
                } 
            }
            if (marked) break;
        }

        while (!que.empty()) {
            int i = que.front()[0];
            int j = que.front()[1];
            int dist = que.front()[2];
            que.pop();

            if (i < 0 || i >= m || j < 0 || j >= n) continue;
            if (grid[i][j] == 1) return dist-1;

            if (grid[i][j] == 0) {
                grid[i][j] = -1;

                que.push({i+1, j, dist+1});
                que.push({i-1, j, dist+1});
                que.push({i, j+1, dist+1});
                que.push({i, j-1, dist+1});
            }
        }

        return 1;
    }
};