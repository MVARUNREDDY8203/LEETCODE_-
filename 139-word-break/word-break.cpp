class Solution {
public:
    unordered_set<string> uset;
    int dp[300];
    
    bool util (int i, string s) {
        if (i >= s.size()) return true;
        if (dp[i] != -1) return dp[i];

        for (int j=i; j<s.size(); j++) {
            string p = s.substr(i, j-i+1);

            if (uset.count(p)) {
                if (util(j+1, s)) return dp[i] = true;
            }
        }

        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for (auto i: wordDict) uset.insert(i);
        memset(dp, -1, sizeof(dp));
        
        return util(0, s);
    }
};


// class Solution {
//     private:
//         unordered_set<string> uset;
// public:
//     bool word_break_util(string s, string curr, vector<string> &wordDict, vector<int> &dp) {
//         if (curr.size() == s.size()) {
//             if (uset.find(curr) != uset.end()) return true;
//             return false;
//         }
//         if (dp[curr.size()] != -1) return dp[curr.size()];

//         bool possible = false;
//         for (auto i: wordDict) {
//             if (i.size() <= s.size() - curr.size()) {
//                 possible = possible | word_break_util(s, curr+i, wordDict, dp);
//                 if (possible) return true;
//             }
//         }
//         return dp[curr.size()] = possible ? 1 : 0;
//     }
//     bool wordBreak(string s, vector<string>& wordDict) {
//         uset.insert(s);
//         vector<int> dp(s.size()+1, -1);
//         return word_break_util(s, "", wordDict, dp);
//     }
// };