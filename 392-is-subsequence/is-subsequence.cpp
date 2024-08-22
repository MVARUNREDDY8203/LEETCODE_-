class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l = 0, r = 0;
        while (r < t.size() && l < s.size()) {
            if (s[l] == t[r]) {
                l++;
            }
            r++;
        }
        return l == s.size();
    }
};