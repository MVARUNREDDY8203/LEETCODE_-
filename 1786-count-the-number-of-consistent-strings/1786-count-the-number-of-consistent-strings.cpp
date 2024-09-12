class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int freq[26];
        memset(freq, 0, sizeof(freq));
        for (int i=0; i<allowed.size(); i++) freq[allowed[i] - 'a']++;
        int cnt = 0;
        for (auto word: words) {
            bool flag = true;
            for (auto j: word) {
                if (freq[j - 'a'] == 0) {
                    flag = false;
                    break;
                }
            }
            if (flag) cnt++;
        }
        return cnt;
    }
};