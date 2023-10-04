// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         if (s.size() == 1) return 1;
//         int al = 0;
//         int ar = 0;
//         // i centered;
//         for (int i=0; i<s.size(); i++) {
//             int l = i, r = i;
//             while (l >=0 && r < s.size()) {
//                 if (s[l] != s[r]) break;
//                 l--;
//                 r++;
//             }
//             l++;
//             r--;
//             if (r-l+1 > ar-al+1) {
//                 al = l;
//                 ar = r;
//             }
//         }

//         // i, i+1 centered
//         for (int i=1; i<s.size(); i++) {
//             int l = i-1, r = i;
//             while (l >=0 && r < s.size()) {
//                 if (s[l] != s[r]) break;
//                 l--;
//                 r++;
//             }
//             l++;
//             r--;
//             if (r-l+1 > ar-al+1) {
//                 al = l;
//                 ar = r;
//             }
//         }

//         return ar-al+1;
//     }
// };

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