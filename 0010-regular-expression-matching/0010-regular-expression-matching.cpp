class Solution {
public:
    bool util(int i, int j, string &s, string &p) {
        if (j >= p.size()) {
            if (i >= s.size()) return true;
            return false;
        }
        if (i >= s.size()) {
            if (p[j+1] == '*') return util(i, j+2, s, p);
            return false;
        }

        if (j+1 < p.size() && p[j+1] == '*') {
            bool ans = false;
            ans |= util(i, j+2, s, p);
            if (p[j] == '.' || p[j] == s[i]) ans |= util(i+1, j, s, p);
            return ans;
        }

        if (p[j] == '.') return util(i+1, j+1, s, p);

        if (p[j] == s[i]) return util(i+1, j+1, s, p);
        return false;
    }
    bool isMatch(string s, string p) {
        return util(0, 0, s, p);
    }
};