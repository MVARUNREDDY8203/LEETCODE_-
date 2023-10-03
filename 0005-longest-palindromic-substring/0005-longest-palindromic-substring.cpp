class Solution {
public:
    bool check_palindrome(string &s, int l, int r, vector<vector<bool>> &dp) {
        if (l == r) return dp[l][r] = true;

        if (r-l == 1) return (s[l] == s[r] ? dp[l][r] = true: dp[l][r] = false);

        if (s[l] == s[r] && dp[l+1][r-1] == true) return dp[l][r] = true;
        return dp[l][r] = false;
    }
    string longestPalindrome(string s) {
        int al =0;
        int ar =0;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int len=0; len<s.size(); len++) {
            for (int i=0, j=len; j<s.size();i++, j++) {
                if(check_palindrome(s, i, j, dp)){
                    if (ar-al+1 < j-i+1) {
                        al = i;
                        ar = j;
                    }                
                }
            }
        }
        return s.substr(al, ar-al+1);
    }
};