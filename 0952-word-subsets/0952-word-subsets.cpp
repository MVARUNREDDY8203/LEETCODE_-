class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> freq1(26, 0);
        for (int i=0; i<words2.size(); i++) {
            vector<int> freq(26, 0);
            for (int j=0; j<words2[i].size(); j++) {
                freq[words2[i][j] - 'a']++;
            }
            for (int i=0; i<26; i++) {
                freq1[i] = max(freq1[i], freq[i]);
            }
        }
        vector<string> ans;
        for (int i=0; i<words1.size(); i++) {
            vector<int> freq2(26, 0);
            for (int j=0; j<words1[i].size(); j++) {
                freq2[words1[i][j] - 'a']++;
            }
            bool flag = true;
            for (int j=0; j<26; j++) {
                if (freq1[j] && freq2[j] < freq1[j]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                ans.push_back(words1[i]);
            }
        }
        return ans;
    }
};