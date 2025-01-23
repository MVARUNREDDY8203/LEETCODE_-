class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        unsigned char m = grid.size(), n = grid[0].size();
        unsigned char rows[251];
        unsigned char cols[251];
        for (unsigned char i=0; i<m; i++) {
            for (unsigned char j=0; j<n; j++) {
                if (grid[i][j]) {
                    rows[i]++;
                    cols[j]++;
                }
            }
        }
        short ans = 0;
        for (unsigned char i=0; i<m; i++) {
            for (unsigned char j=0; j<n; j++) {
                if (grid[i][j] && (rows[i] > 1 || cols[j] > 1)) {
                    ans++;
                }
            }
        }

        return ans;
    }
};