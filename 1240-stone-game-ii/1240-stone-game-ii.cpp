class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        int dp[2][101][101];
        memset(dp,-1, sizeof(dp));
        function<int(int, int, int)> util = [&](int i, int m, int turn)-> int {
            if (i >= n) return 0;
            
            if (dp[turn][i][m] != -1) return dp[turn][i][m];
            int stones = 0;
            int ans = turn ? 0 : INT_MAX;
            for (int x = 1; x <= 2*m; x++) {
                if (i+x-1 >= n) break;
                stones += piles[i+x-1];
                if (turn) ans = max(ans, stones + util(i+x, max(m, x), 0));
                else ans = min(ans, util(i+x, max(m, x), 1));
            }

            return dp[turn][i][m] = ans;
        };

        return util(0, 1, 1);
    }
};