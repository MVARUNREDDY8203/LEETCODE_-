class Solution {
public:
    int minimumLength(string s) {
        int freq[26];
        memset(freq, 0, sizeof(freq));
        int n = s.size(), ans = s.size();
        for (int i=0; i<n; i++) {
            freq[s[i] - 'a']++;
            if (freq[s[i] - 'a'] == 3) {
                ans -= 2;
                freq[s[i] - 'a'] -= 2;
            }
        }
        return ans;
    }
};