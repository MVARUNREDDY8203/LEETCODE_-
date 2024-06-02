class Solution {
public:
    queue<vector<int>> que;
    vector<vector<int>> visited;
    vector<vector<int>> dist_map;

    void bfs(int p, int q, int a, vector<vector<int>> &grid) {
        int max_dist = 0;
        int m = grid.size(), n = grid[0].size();
        que.push({p-1, q, 1});
        que.push({p+1, q, 1});
        que.push({p, q-1, 1});
        que.push({p, q+1, 1});

        while (!que.empty()) {
            int i = que.front()[0];
            int j = que.front()[1];
            int dist = que.front()[2];
            que.pop();
            
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1 || visited[i][j] == a) continue;

            max_dist = max(max_dist, dist);
            dist_map[i][j] = min(dist_map[i][j], dist);
            visited[i][j] = a;

            que.push({i, j+1, dist+1});
            que.push({i, j-1, dist+1});
            que.push({i+1, j, dist+1});
            que.push({i-1, j, dist+1});
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        dist_map.resize(m, vector<int>(n, INT_MAX));
        visited.resize(m, vector<int>(n, -1));

        int a = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 2) {
                    bfs(i, j, a++, grid);
                }
            }
        }

        int ans = -1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cout<<dist_map[i][j]<<" ";

                if (grid[i][j] == 1) {
                    if (visited[i][j] == -1) return -1;
                    ans = max(ans, dist_map[i][j]);
                }
            }
            cout<<endl;
        }
        return ans == -1 ? 0 : ans;
    }
};