class Solution {
public:
    int partitionString(string s) {
        int n = s.size(), cnt = 1;
        int freq[26];
        memset(freq, 0, sizeof(freq));
        for (int i=0; i<n; i++) {
            if (freq[s[i] - 'a'] > 0) {
                memset(freq, 0, sizeof(freq));
                cnt++;
            }
            freq[s[i] - 'a']++;
        }
        return cnt;
    }
};