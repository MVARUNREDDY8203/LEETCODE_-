class Solution {
public:
    unordered_map<string, int> ump;
    unordered_map<string, bool> dp;
    bool util(string &s) {
        if (s.size() == 0) return true;

        if (dp.count(s)) return dp[s];

        string temp = "";
        for (int i=0; i<s.size(); i++) {
            temp += s[i];
            if (ump.count(temp)) {
                string passer = s.substr(i+1);
                if (util(passer)) return dp[s] = true;
            }
        }
        return dp[s] = false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        for (auto word: words) ump[word]++;
        vector<string> ans;
        for (auto word: words) {
            dp.clear();
            ump.erase(word);
            if (util(word)) ans.push_back(word);
            ump[word]++;
        }
        return ans;
    }
};