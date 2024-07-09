class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<bool>> isPalindrome(n, vector<bool>(n, false));

        int cnt = 0;
        for (int i=0; i<n; i++) isPalindrome[i][i] = true, cnt++;

        for (int i=0; i<n-1; i++) {
            if (s[i] == s[i+1]) {
                isPalindrome[i][i+1] = true;
                cnt++;
            }
        }

        for (int len=3; len<=n; len++) {
            for (int i=0; i<n-len+1; i++) {
                if (s[i] == s[i+len-1] && isPalindrome[i+1][i+len-2]) {
                    isPalindrome[i][i+len-1] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};