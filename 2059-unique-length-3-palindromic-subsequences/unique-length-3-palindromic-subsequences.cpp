class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> fo(26, 100001);
        vector<int> lo(26, -1);
        int n = s.size();
        for (int i=0; i<n; i++) {
            fo[s[i] - 'a'] = min(fo[s[i] - 'a'], i);
            lo[s[i] - 'a'] = max(lo[s[i] - 'a'], i);
        }

        unordered_map<int, unordered_set<int>> ump;
        for (int i=1; i<n-1; i++) {
            for (int j=0; j<26; j++) {
                if (fo[j] < i && i < lo[j]) {
                    ump[j].insert(s[i]);
                }
            }
        }
        int ans = 0;
        for (int j=0; j<26; j++) ans += ump[j].size();
        return ans;
    }
};