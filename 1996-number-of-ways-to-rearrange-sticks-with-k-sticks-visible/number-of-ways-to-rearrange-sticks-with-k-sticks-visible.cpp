class Solution {
public:
    int dp[1001][1001];
    long long int util (int n, int k) {
        if (n == k) return 1;
        if (n < k || n <= 0 || k <= 0) return 0;

        if (dp[n][k] != -1) return dp[n][k];

        long long int ans = 0;
        // choosing the tallest stick at the rightmost position
        ans += util(n-1, k-1);
        // choosing n-1 sticks one by one to be at the rightmost pos, we'll be left with 
        ans += (n-1) * util(n-1, k);

        return dp[n][k] = ans % 1000000007;
    }
    int rearrangeSticks(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return util(n, k);
    }
};