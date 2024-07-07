class Solution {
public:
    int dp[1000][1000];
    int lcs(int i, int j, string &t1, string &t2) {
        if (i >= t1.size()) return 0;
        if (j >= t2.size()) return 0;

        if (dp[i][j] != -1) return dp[i][j];
        if (t1[i] == t2[j]) {
            return dp[i][j] = 1 + lcs(i+1, j+1, t1, t2);
        }
        return dp[i][j] = max(lcs(i+1, j, t1, t2), lcs(i, j+1, t1, t2));
    }
    int longestCommonSubsequence(string t1, string t2) {
        memset(dp, -1, sizeof(dp));
        return lcs(0, 0, t1, t2);
    }
};