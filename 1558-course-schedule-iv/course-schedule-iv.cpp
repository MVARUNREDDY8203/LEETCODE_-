class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);

        short cache[101][101];
        memset(cache, -1, sizeof(cache));

        vector<vector<int>> graph(n+1, vector<int>(0));
        for (auto i: pre) {
            graph[i[0]].push_back(i[1]);
        }

        bool vis[101];
        memset(vis, 0, sizeof(vis));
        function<bool(int, int)> dfs = [&](int i, int target) -> bool {
            if (i == target) return true;
            if (vis[i]) return false;
            if (cache[i][target] != -1) return cache[i][target];

            vis[i] = 1;
            for (int j=0; j<graph[i].size(); j++) {
                if (dfs(graph[i][j], target)) {
                    vis[i] = 0;
                    return cache[i][target] = true;
                }
            }
            vis[i] = 0;

            return cache[i][target] = false;
        };
        
        vector<bool> ans(queries.size(), 0);
        int k = 0;
        for (auto i: queries) {
            ans[k++] = dfs(i[0], i[1]);
        }

        return ans;
    }
};