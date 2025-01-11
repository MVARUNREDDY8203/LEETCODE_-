class Solution {
public:
    bool canConstruct(string s, int k) {
        if (k > s.size()) return 0;
        int freq[26];
        for (int i=0; i<s.size(); i++) freq[s[i] - 'a']++;
        int ones = 0, twos = 0;
        for (int i=0; i<26; i++) {
            ones += freq[i] % 2;
            twos += (freq[i]/2);
        }
        if (k < ones) return false;
        return true;
    }
};