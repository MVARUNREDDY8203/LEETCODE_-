class Solution {
public: 
    struct cmp {
        bool operator()(const vector<int>&a, const vector<int>&b) {
            return a[0] > b[0];
        }
    };
    int trapRainWater(vector<vector<int>>& hmap) {
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        int m = hmap.size(), n = hmap[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        for (int i=0; i<m; i++) {
            pq.push({hmap[i][0], i, 0});
            pq.push({hmap[i][n-1], i, n-1});
        }
        for (int j=0; j<n; j++) {
            pq.push({hmap[0][j], 0, j});
            pq.push({hmap[m-1][j], m-1, j});
        }
        int ans = 0;
        function<void(int, int, int, int)> check = [&](int i, int j, int a, int b) -> void {
            if (i <= 0 || i >= m-1 || j <= 0 || j >= n-1) return;
            if (vis[i][j]) return;

            if (hmap[i][j] < hmap[a][b]) {
                ans += hmap[a][b] - hmap[i][j];
                hmap[i][j] = hmap[a][b];
            }

            pq.push({hmap[i][j], i, j});
        };
        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();
            int i = curr[1], j = curr[2];
            if (i < 0 || j < 0 || i >= m || j >= n) continue;
            if (vis[i][j]) continue;

            vis[i][j] = 1;

            check(i+1, j, i, j);
            check(i-1, j, i, j);
            check(i, j-1, i, j);
            check(i, j+1, i, j);
        }
        return ans;
    }
};