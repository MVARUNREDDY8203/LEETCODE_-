class Solution {
public:
    int dp[201][201];
    int util (int i, int j, vector<vector<int>>& tri) {
        if (i >= tri.size()) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = tri[i][j] + min(util(i+1, j, tri), util(i+1, j+1, tri));
    }
    int minimumTotal(vector<vector<int>>& tri) {
        memset(dp, -1, sizeof(dp));
        return util(0, 0, tri);
    }
};