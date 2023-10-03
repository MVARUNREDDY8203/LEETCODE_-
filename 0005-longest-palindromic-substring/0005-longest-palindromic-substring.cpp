class Solution {
public:
    string longestPalindrome(string s) {
        int al = 0, ar = 0, n = s.size();
        if (n == 1) return s;
        // odd length mfs
        for (int i=0; i<n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n) {
                if (s[l] != s[r]) break;
                l--;
                r++;
            }
            l++;
            r--;
            if (ar-al+1 < r-l+1) {
                al = l;
                ar = r;
            }
        }
        
        // even length mfs
        for (int i=1; i<n; i++) {
            int l = i-1, r = i;
            if (s[l] != s[r]) continue;
            while (l >= 0 && r < n) {
                if (s[l] != s[r]) break;
                l--;
                r++;
            }
            l++;
            r--;
            if (ar-al+1 < r-l+1) {
                al = l;
                ar = r;
            }
        }

        return s.substr(al, ar-al+1);
    }
};
// class Solution {
// public:
//     bool check_palindrome(string &s, int l, int r, vector<vector<bool>> &dp) {
//         if (l == r) return dp[l][r] = true;

//         if (r-l == 1) return (s[l] == s[r] ? dp[l][r] = true: dp[l][r] = false);

//         if (s[l] == s[r] && dp[l+1][r-1] == true) return dp[l][r] = true;
//         return dp[l][r] = false;
//     }
//     string longestPalindrome(string s) {
//         int al =0, ar =0;
//         vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
//         for (int len=0; len<s.size(); len++) {
//             for (int i=0, j=len; j<s.size();i++, j++) {
//                 if(check_palindrome(s, i, j, dp)){
//                     if (ar-al+1 < j-i+1) {
//                         al = i;
//                         ar = j;
//                     }                
//                 }
//             }
//         }
//         return s.substr(al, ar-al+1);
//     }
// };