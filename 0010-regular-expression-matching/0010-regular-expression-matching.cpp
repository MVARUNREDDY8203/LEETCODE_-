class Solution {
public:
    int dp[21][21];
    bool util(int i, int j, string &s, string &p) {
        if (j >= p.size()) {
            if (i >= s.size()) return true;
            return false;
        }
        if (i >= s.size()) {
            if (p[j+1] == '*') return util(i, j+2, s, p);
            return false;
        }
        if (dp[i][j] != -1) return dp[i][j];

        if (j+1 < p.size() && p[j+1] == '*') {
            bool ans = false;
            ans |= util(i, j+2, s, p);
            if (p[j] == '.' || p[j] == s[i]) ans |= util(i+1, j, s, p);
            return dp[i][j] = ans;
        }

        if (p[j] == '.') return dp[i][j] = util(i+1, j+1, s, p);

        if (p[j] == s[i]) return dp[i][j] = util(i+1, j+1, s, p);
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        memset(dp, -1, sizeof(dp));
        return util(0, 0, s, p);
    }
};