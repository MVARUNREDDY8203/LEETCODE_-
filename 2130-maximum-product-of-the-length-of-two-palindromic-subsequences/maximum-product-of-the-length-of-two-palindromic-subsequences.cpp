class Solution {
public:
    bool isPalindrome(string &s1) {
        int n = s1.size() - 1;
        int i = 0;
        while (i < n) {
            if (s1[i++] != s1[n--]) return false;
        }
        return true;
    }
    int dfs(int i, string &s1, string &s2, string &s) {
        if (i >= s.size()) {
            if (isPalindrome(s1) && isPalindrome(s2)) return s1.size() * s2.size();
            return 0;
        }
        int ans = 0;

        s1 += s[i];
        ans = dfs(i+1, s1, s2, s);
        s1.pop_back();

        s2 += s[i];
        ans = max(ans, dfs(i+1, s1, s2, s));
        s2.pop_back();

        ans = max(ans, dfs(i+1, s1, s2, s));
        return ans;
    }
    int maxProduct(string s) {
        string s1 = "";
        string s2 = "";
        return dfs(0, s1, s2, s);
    }
};