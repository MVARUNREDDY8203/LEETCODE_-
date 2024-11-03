class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        for (int i=0; i<n; i++) {
            int l = 0, r = i, j = 0;
            while (r < n && s[r] == goal[j]) {
                r++;
                j++;
            }
            if (r != n) continue;
            while (j < n && s[l] == goal[j]) {
                l++;
                j++;
            }
            if (j == n) return true;
        }
        return false;
    }
};