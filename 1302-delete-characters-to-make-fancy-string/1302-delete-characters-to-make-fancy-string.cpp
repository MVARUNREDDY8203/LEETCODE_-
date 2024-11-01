class Solution {
public:
    string makeFancyString(string s) {
        char prev = '0';
        int curr = 0, n = s.size();
        string ans = "";
        for (int i=0; i<n; i++) {
            if (s[i] == prev) {
                curr++;
            }
            else {
                curr = 1;
                prev = s[i];
            }
            if (curr <= 2) {
                ans += s[i];
            }
        }
        return ans;
    }
};