class Solution {
public:
    bool isCircularSentence(string s) {
        char p = s.back();
        int n = s.size();
        string curr = "";
        for (int i=0; i<n; i++) {
            if (s[i] == ' ') {
                p = curr.back();
                curr = "";
                continue;
            }
            curr += s[i];
            if (curr[0] != p) return false;
        }
        return true;
    }
};