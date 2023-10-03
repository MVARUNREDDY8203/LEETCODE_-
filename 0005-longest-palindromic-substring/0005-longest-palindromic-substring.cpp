// class Solution {
// private: 
//     bool solve(vector<vector<bool>> &dp, int i, int j, string &s){
//         if(i == j){
//             return dp[i][j] = true;
//         }
//         if(j-i == 1){
//             if(s[i] == s[j]){
//                 return dp[i][j] = true;
//             }
//             else{
//                 return dp[i][j] = false;
//             }
//         }
//         if(s[i] == s[j] && dp[i+1][j-1] == true){
//             return dp[i][j] = true;
//         } else {
//             return dp[i][j] = false;
//         }
//     }
// public:
//     string longestPalindrome(string s) {
//         int n = s.size();
//         int startIndex = 0; int maxlen = 0;
//         vector<vector<bool>> dp(n, vector<bool>(n, false));
//         for(int g=0; g<n; g++){
//             for(int i=0, j=g; j<n; i++, j++){
//                 solve(dp, i, j, s);
//                 if(dp[i][j] == true){
//                     if(j-i+1 > maxlen){
//                         startIndex = i;
//                         maxlen = j-i+1;
//                     }
//                 }
//             }
//         }
//         return s.substr(startIndex, maxlen);
//     }
// };
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