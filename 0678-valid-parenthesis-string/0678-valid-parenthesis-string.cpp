class Solution {
public:
    bool checkValidString(string s) {
        stack<int> ob;
        stack<int> star;
        int n = s.size();
        for (int i=0; i<n; i++) {
            if (s[i] == '(') ob.push(i);
            else if(s[i] == ')') {
                if (!ob.empty()) ob.pop();
                else if (!star.empty()) star.pop();
                else return false;
            }
            else star.push(i);
        }
        if (ob.empty()) return true;
        while (!ob.empty()) {
            if (star.empty() || star.top() < ob.top()) return false;
            star.pop();
            ob.pop();
        }
        return ob.empty();
    }
};


// class Solution {
// public:
//     bool cvs(string s, int i, int l, vector<vector<int>> &dp) {
//         if (i > s.size()-1) return l == 0;  

//         if (dp[i][l] != 2) return dp[i][l];

//         int ans = 0;
//         if (s[i] == '(') ans = cvs(s, i+1, l+1, dp);
//         else if (s[i] == ')') ans = (l > 0 ? cvs(s, i+1, l-1, dp) : false);
//         else ans = cvs(s, i+1, l, dp) || cvs(s, i+1, l+1, dp) || (l > 0 ? cvs(s, i+1, l-1, dp): false);

//         return dp[i][l] = ans;
//     }
//     bool checkValidString(string s) {
//         vector<vector<int>> dp(103, vector<int>(103, 2));
//         return cvs(s, 0, 0, dp);
//     }
// };



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