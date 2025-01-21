class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        if (n == 1) return 0;
        vector<vector<long long int>> gridsum(2, vector<long long int>(n, 0));
        gridsum[0][0] = grid[0][0];
        gridsum[1][0] = grid[1][0];
        for (int i=1; i<n; i++) {
            gridsum[0][i] = gridsum[0][i-1] + grid[0][i];
            cout<<gridsum[0].size()<<" ";
            gridsum[1][i] = gridsum[1][i-1] + grid[1][i];
            
        }
        
        long long int ans = min(gridsum[0][n-1] - gridsum[0][0], gridsum[1][n-2]);
        for (int i=1; i<n-1; i++) {
            ans = min(ans, max(gridsum[0][n-1] - gridsum[0][i], gridsum[1][i-1]));
        }
        return ans;
    }
};