class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<string, int> ump;
        int n = s.size();
        unordered_set<string> ans;
        for (int i=0; i<=n-10; i++) {
            string t = s.substr(i, 10);
            if (ump.count(t)) {
                ans.insert(t);
            }
            ump[t]++;
        }
        vector<string> real_ans;
        for (auto i: ans) {
            real_ans.push_back(i);
        }
        return real_ans;
    }
};