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

        unordered_map<string, int> ump;
        for (int i=1; i<n-1; i++) {
            for (int j=0; j<26; j++) {
                if (fo[j] < i && i < lo[j]) {
                    string t = "";
                    t += (fo[j] + 'a');
                    t += s[i];
                    t += (fo[j] + 'a');
                    ump[t]++;
                }
            }
        }
        return ump.size();
    }
};