class Solution {
public:
    int dp[601][101][101];
    int dfs(int i, int m, int n, vector<pair<int, int>> &len) {
        if (m < 0 || n < 0) return -1;
        if (m == 0 && n == 0) return 0;
        if (i >= len.size()) return 0;

        if (dp[i][m][n] != -1) return dp[i][m][n];

        int take = 1 + dfs(i+1, m - len[i].first, n - len[i].second, len);
        int not_take = dfs(i+1, m, n, len);
        return dp[i][m][n] = max(take, not_take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        vector<pair<int, int>> len(strs.size());
        memset(dp, -1, sizeof(dp));
        
        for (int i=0; i<strs.size(); i++) {
            int ones_cnt = 0, zero_cnt = 0;
            for (int j=0; j<strs[i].size(); j++) strs[i][j] == '0' ? zero_cnt++ : ones_cnt++;
            len[i].first = zero_cnt;
            len[i].second = ones_cnt;
        }
        return dfs(0, m, n, len);

    }
};