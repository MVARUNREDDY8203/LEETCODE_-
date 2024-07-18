class Solution {
public:
    int sq[101];
    unordered_map<int, int> sq_map;
    int dp[10001][101];
    int util(int i, int n) {
        if (n == 0) return 0;
        if (i <= 0) return 1e5;
        if (dp[n][i] != -1) return dp[n][i];
        
        if (n < sq[i]) return util(i-1, n);

        if (sq_map[n] > 0) return 1;

        int not_take = INT_MAX;
        int take = INT_MAX;


        take = 1 + util(i, n - sq[i]);
        not_take = util(i-1, n);

        return dp[n][i] = min(take, not_take);
    }
    int numSquares(int n) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        for (int i=0; i<=100; i++) sq[i] = i*i, sq_map[sq[i]]++;
        memset(dp, -1, sizeof(dp));
        return util(100, n);
    }
};