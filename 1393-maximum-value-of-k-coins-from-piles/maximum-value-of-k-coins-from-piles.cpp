class Solution {
public:
    int dp[1001][2001];
    int util(int i, int k, vector<vector<int>>&piles) {
        if (i >= piles.size()) return 0;
        if (k <= 0) return 0;

        if (dp[i][k] != -1) return dp[i][k];

        int ans = util(i+1, k, piles);
        int curr = 0;
        for (int j=0; j<piles[i].size(); j++) {
            curr += piles[i][j];
            int rem = k - (j+1);
            if (rem < 0) break;
            ans = max(ans, curr + util(i+1, rem, piles));
        }
        return dp[i][k] = ans;
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(dp, -1, sizeof(dp));
        return util(0, k, piles);
    }
};