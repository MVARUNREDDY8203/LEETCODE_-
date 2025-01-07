class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_map<string, int> ump;
        for (int i=0; i<words.size(); i++) {
            for (int j=0; j<words[i].size(); j++) {
                string temp = "";
                for (int k=j; k<words[i].size(); k++) {
                    temp += words[i][k];
                    ump[temp]++;
                }
            }
        }
        vector<string> ans;
        for (int i=0; i<words.size(); i++) if (ump[words[i]] > 1) ans.push_back(words[i]);
        return ans;
    }
};