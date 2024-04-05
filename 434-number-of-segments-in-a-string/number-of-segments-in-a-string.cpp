class Solution {
public:
    int countSegments(string s) {
        int cnt = 0;
        string t= "";
        for (int i=0; i<s.size(); i++) {
            if (s[i] == ' ') {
                if (t.size() > 0) cnt++;
                t = "";
            }
            else t += s[i];
        }
        // if (s[i] == ' ') {
            if (t.size() > 0) cnt++;
            t = "";
        // }
        return cnt;
    }
};