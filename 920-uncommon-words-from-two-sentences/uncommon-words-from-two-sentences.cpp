class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        string item;
        stringstream ss(s1);
        unordered_map<string, int> ump1;
        while (getline(ss, item, ' ')) {
            ump1[item]++;
        }
        stringstream ss2(s2);
        while (getline(ss2, item, ' ')) {
            ump1[item]++;
        }
        vector<string> ans;
        for (auto i: ump1) if (i.second == 1) ans.push_back(i.first);
        return ans;      
    }
};