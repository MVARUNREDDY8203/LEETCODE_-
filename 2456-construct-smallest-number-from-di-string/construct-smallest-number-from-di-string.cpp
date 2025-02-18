class Solution {
public:
    bool used[10];
    bool util(int i, int n, string &pattern, string &ans) {
        cout<<i<<endl;
        if (i >= n+1) return true;

        for (int j=1; j <= 9; j++) {
            if (i == 0) {
                used[j] = 1;
                ans[i] = '0' + j;
                if (util(i+1, n, pattern, ans)) return true;
                used[j] = 0;
                ans[i] = '0';
            } 
            else if (!used[j]) {
                if ((pattern[i-1] == 'I' && j > ans[i-1] - '0') || (pattern[i-1] == 'D' && j < ans[i-1] - '0')) {
                    used[j] = 1;
                    ans[i] = '0' + j;
                    if (util(i+1, n, pattern, ans)) return true;
                    used[j] = 0;
                    ans[i] = '0';
                } 
            }
        }
        cout<<ans<<endl;
        return false;
    }
    string smallestNumber(string pattern) {
        memset(used, 0, sizeof(used));
        int n = pattern.size();
        string ans = "";
        for (int i=0; i<=n; i++) ans += '0';
        util(0, n, pattern, ans);
        return ans;
    }
};