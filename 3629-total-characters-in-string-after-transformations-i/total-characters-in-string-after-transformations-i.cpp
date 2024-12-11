class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int freq[26];
        memset(freq, 0, sizeof(freq));
        for (int i=0; i<s.size(); i++) freq[s[i] - 'a']++;
        
        int mod = 1e9 + 7;

        for (int i=0; i<t; i++) {
            int freq2[26];
            memset(freq2, 0, sizeof(freq2));

            for (int j=0; j<25; j++) freq2[j+1] = freq[j];

            freq2[0] = (freq2[0] + freq[25]) % mod;
            freq2[1] = (freq2[1] + freq[25]) % mod;
            for (int j=0; j<26; j++) freq[j] = freq2[j];
        }

        int ans = 0;
        for (int i=0; i<26; i++) ans = (ans + freq[i]) % mod;

        return ans;
    }
};