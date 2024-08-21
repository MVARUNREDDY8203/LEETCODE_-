class Solution {
public:
    int strangePrinter(string s) {
        int dp[101][101];
        memset(dp, -1, sizeof(dp));
        function<int(int, int)> util = [&](int l, int r) -> int {
            if (l >= r) return 1;
            if (dp[l][r] != -1) return dp[l][r];
            int ans = INT_MAX;
            for (int k=l; k<r; k++) {
                ans = min(ans, util(l, k) + util(k+1, r));
            }

            return dp[l][r] = s[l] == s[r] ? ans - 1 : ans;
        };
        return util(0, s.size()-1);
    }
};