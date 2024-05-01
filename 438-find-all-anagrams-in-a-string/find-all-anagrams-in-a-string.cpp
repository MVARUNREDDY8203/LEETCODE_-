class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (p.size() > s.size()) return {};

        int freq[26];
        memset(freq, 0, sizeof(freq));
        for (int i=0; i<p.size(); i++) freq[p[i] - 'a']++;

        vector<int> ans;
        int l = 0, r = 0, n = s.size(), cnt = 0;
        for (r=0; r<p.size(); r++) {
            if (freq[s[r] - 'a'] > 0) {
                cnt++;
            }
            freq[s[r] - 'a']--;
        }
        while (r < n) {
            if (cnt == p.size()) ans.push_back(l);

            if (++freq[s[l++] - 'a'] > 0) cnt--;
            
            if (freq[s[r] - 'a'] > 0) {
                cnt++;
            }
            freq[s[r] - 'a']--;
            r++;
        }
        if (cnt == p.size()) ans.push_back(l);

        return ans;
    }
};