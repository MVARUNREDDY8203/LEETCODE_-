class Solution {
    int n = 0;
    int total = 0;
    int dp[502][252];
public:
    bool util (vector<int> &piles, int i, int m, int sum) {
        if (i >= n) {
            if (m == n/2) {
                return dp[i][m] = sum > total - sum;
            }
            return dp[i][m] = false;
        }
        if (m == n/2) {
            return dp[i][m] = sum > total - sum;
        }

        // if (dp.count(sum))
        if (dp[i][m] != -1) return dp[i][m];
        
        return dp[i][m] = util (piles, i+1, m, sum) || util (piles, i+1, m+1, sum + piles[i]);
    }
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        memset(dp, -1, sizeof(dp));
        for (auto i: piles) total += i;
        return util(piles, 0, 0, 0);
    }
};