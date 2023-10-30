class Solution {
public:
    bool cvs(string s, int i, int l, vector<vector<int>> &dp) {
        if (i > s.size()-1) return l == 0;  

        if (dp[i][l] != 2) return dp[i][l];

        int ans = 0;
        if (s[i] == '(') ans = cvs(s, i+1, l+1, dp);
        else if (s[i] == ')') ans = (l > 0 ? cvs(s, i+1, l-1, dp) : false);
        else ans = cvs(s, i+1, l, dp) || cvs(s, i+1, l+1, dp) || (l > 0 ? cvs(s, i+1, l-1, dp): false);

        return dp[i][l] = ans;
    }
    bool checkValidString(string s) {
        vector<vector<int>> dp(103, vector<int>(103, 2));
        return cvs(s, 0, 0, dp);
    }
};



// class Solution {
// public:
//     bool cvs(string s, int i, int l) {
//         if (i > s.size()-1) return l == 0;

//         if (s[i] == '(') return cvs(s, i+1, l+1);
//         if (s[i] == ')') return l > 0 ? cvs(s, i+1, l-1) : false;

//         return cvs(s, i+1, l) || cvs(s, i+1, l+1) || cvs(s, i+1, l-1);
//     }
//     bool checkValidString(string s) {
//         return cvs(s, 0, 0);
//     }
// };