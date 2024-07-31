class Solution {
public:
    unordered_map<int, int> dp;
    int util(int n) {
        if (n == 0) return -1;
        if (dp.count(n)) return dp[n];

        int ans = 1 + min(n%2 + util(n/2), n%3 + util(n/3));

        return dp[n] = ans;
    }
    int minDays(int n) {
        // memset(dp, -1, sizeof(dp));
        return util(n);
    }
};