class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dict;
        for (string word : dictionary) dict.insert(word);
        
        int dp[51];
        memset(dp, -1, sizeof(dp));
        function<int(int)> util = [&](int i) -> int {
            if (i >= n) return 0;
            if (dp[i] != -1) return dp[i];

            int not_take = 1 + util(i+1);

            int take = 1e9;
            for (int j=i; j<n; j++) {
                string curr = s.substr(i, j-i+1);
                if (dict.count(curr)) {
                    take = min(take, util(j+1));
                }
            }
            return dp[i] = min(take, not_take);
        };
        
        return util(0);
    }
};