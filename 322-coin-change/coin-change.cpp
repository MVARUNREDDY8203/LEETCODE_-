class Solution {
public:
    int dp[10001];
    int util(vector<int>&coins, int amt) {
        if (amt == 0) return 0;
        if (amt < 0) return 1e5;

        if (dp[amt] != -1) return dp[amt];

        int n = coins.size();
        int ans = 1e5;
        for (int i=0; i<n; i++) {
            ans = min(ans, 1 + util(coins, amt-coins[i]));
        }

        return dp[amt] = ans;
    }
    int coinChange(vector<int>& coins, int amt) {
        memset(dp, -1, sizeof(dp));
        int ans = util(coins, amt);

        if (ans >= 1e5) return -1;
        return ans;        
    }
};