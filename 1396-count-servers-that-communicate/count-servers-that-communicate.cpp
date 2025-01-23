class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unsigned char m = grid.size(), n = grid[0].size();
        bool rows[251];
        bool cols[251];
        for (unsigned char i=0; i<m; i++) {
            unsigned char cnt = 0;
            for (unsigned char j=0; j<n; j++) {
                if (grid[i][j]) {
                    cnt++;
                }
                if (cnt == 2) break;
            }
            if (cnt == 2) rows[i] = 1;
        }
        for (unsigned char j=0; j<n; j++) {
            unsigned char cnt = 0;
            for (unsigned char i=0; i<m; i++) {
                if (grid[i][j]) {
                    cnt++;
                }
                if (cnt == 2) break;
            }
            if (cnt == 2) cols[j] = 1;
        }

        short ans = 0;
        for (unsigned char i=0; i<m; i++) {
            for (unsigned char j=0; j<n; j++) {
                if (grid[i][j] && (rows[i] || cols[j])) {
                    ans++;
                }
            }
        }

        return ans;
    }
};