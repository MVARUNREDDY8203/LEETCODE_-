class Solution {
public:
    long long minimumSteps(string s) {
        long long int ans = 0, l = 0, r = s.size()-1;
        while (s[l] == 0) l++;
        while (s[r] == 1) r--;
        int j = r, i = r;
        while (i >= l) {
            if (s[i] == '1') {
                ans += j - i;
                j--;
            }
            i--;
        }
        return ans;
    }
};