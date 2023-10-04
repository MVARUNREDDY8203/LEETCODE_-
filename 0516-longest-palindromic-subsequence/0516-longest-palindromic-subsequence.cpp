class Solution {
public:
    int lpsq(string &s, string &rs, int l, int r, vector<vector<int>> &dp) {
        if (l >= s.size() || r >= rs.size()) return 0;
        if (dp[l][r] != -1) return dp[l][r];


        if (s[l] == rs[r]) return dp[l][r] = 1 + lpsq(s, rs, l+1, r+1, dp);
        return dp[l][r] = max(lpsq(s, rs, l+1, r, dp), lpsq(s, rs, l, r+1, dp));
    }
    int longestPalindromeSubseq(string s) {
        string rs = s;
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), -1));
        reverse(rs.begin(), rs.end());
        return lpsq(s, rs, 0, 0, dp);
    }
};