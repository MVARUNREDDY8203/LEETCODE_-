class Solution {
public:
    int countSubstrings(string s) {
        int cnt = 0, n = s.size();
        for (int i=0; i<n; i++) {
            cnt++;
            int l = i-1, r = i+1;
            while (l >= 0 && r <= n-1) {
                if (s[l] != s[r]) break;
                cnt++;
                l--;
                r++;
            }
        }
        for (int i=0; i<n-1; i++) {
            int l = i, r = i+1;
            while (l >= 0 && r <= n-1) {
                if (s[l] != s[r]) break;
                cnt++;
                l--;
                r++;
            }
        }
        return cnt;
    }
};