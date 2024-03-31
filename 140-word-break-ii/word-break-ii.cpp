class Solution {
public:
    vector<string> ans;
    unordered_set<string> uset;
    bool util (int i, string curr, string &s) {
        if (i >= s.size()) {
            ans.push_back(curr);
            return true;
        }
        if (curr.size() > 0) curr += " ";

        bool possible = false;
        for (int j=i; j<s.size(); j++) {
            string p = s.substr(i, j-i+1);
            if (uset.count(p) && util(j+1, curr+p, s)) possible = true;
        }

        return possible;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for (auto i: wordDict) uset.insert(i);
        util(0, "", s);
        return ans;
    }
};