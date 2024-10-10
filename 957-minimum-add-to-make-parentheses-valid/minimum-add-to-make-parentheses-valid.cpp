class Solution {
public:
    int minAddToMakeValid(string s) {
        int l = 0, n = s.size(), cnt = 0;
        vector<int> stk;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == ')' ) {
                if (l > 0) l--;
                else cnt++;
            }
            else l++;
        }
        return cnt+l;
    }
};