class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int n = grid.size();
        bool vis[501][501];
        int csize[501][501];
        // int grid[501][501];
        
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                vis[i][j] = 0;
                csize[i][j] = -1;
                // grid[i][j] = 0;
            }
        }

        function<int(int, int)> count = [&](int a, int b) -> int {
            int cnt = 0;
            
            queue<pair<int, int>> que;
            que.push({a, b});

            while (!que.empty()) {
                int i = que.front().first;
                int j = que.front().second;
                que.pop();
                
                if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 || vis[i][j]) continue;
                vis[i][j] = 1;
                cnt++;

                que.push({i-1, j});
                que.push({i+1, j});
                que.push({i, j+1});
                que.push({i, j-1});
            }

            return cnt;
        };

        function<int(int, int)> count2 = [&](int i, int j) -> int {
            int cnt2 = 1;

            
            unordered_set<int> cset;
            if (i-1 >= 0 && grid[i-1][j] && !cset.count(grid[i-1][j])) {
                cnt2 += csize[i-1][j];
                cset.insert(grid[i-1][j]);
            }

            if (j-1 >= 0 && grid[i][j-1] &&  !cset.count(grid[i][j-1])) {
                cnt2 += csize[i][j-1];
                cset.insert(grid[i][j-1]);
            }

            if (i+1 < n &&  grid[i+1][j] && !cset.count(grid[i+1][j])) {
                cnt2 += csize[i+1][j]; 
                cset.insert(grid[i+1][j]);
            }

            if (j+1 < n && grid[i][j+1] && !cset.count(grid[i][j+1])) {
                cnt2 += csize[i][j+1]; 
                cset.insert(grid[i][j+1]);
            }
            return cnt2;
        };
        
        function<void(int, int, int, int)> mark = [&](int cn, int cs, int a, int b) -> void {            
            queue<pair<int, int>> que;
            que.push({a, b});
            while (!que.empty()) {
                int i = que.front().first;
                int j = que.front().second;
                que.pop();

                if (i < 0 || i >= n || j < 0 || j >= n || grid[i][j] == 0 || csize[i][j] != -1) continue;
                csize[i][j] = cs;
                grid[i][j] = cn;

                que.push({i+1, j});
                que.push({i-1, j});
                que.push({i, j+1});
                que.push({i, j-1});

            }
        };

        int ans = 0;
        int cn = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] && csize[i][j] == -1) {
                    int cnt = count(i, j);
                    mark(++cn, cnt, i, j);
                }
            }
        }

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 0) ans = max(ans, count2(i, j));
                else ans = max(ans, csize[i][j]);
            }
        }

        return ans;
    }
};