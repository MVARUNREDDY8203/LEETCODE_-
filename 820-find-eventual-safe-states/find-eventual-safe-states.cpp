class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        short n = graph.size();
        char isSafe[10001];
        char vis[10001];
        memset(isSafe, -1, sizeof(isSafe));
        memset(vis, 0, sizeof(vis));

        function<bool(short)> dfs = [&](short i) -> bool {
            if (vis[i]) return isSafe[i] = 0;
            if (graph[i].size() == 0) return isSafe[i] = 1;
            if (isSafe[i] != -1) return isSafe[i];

            vis[i] = 1;
            for (short j = 0; j<graph[i].size(); j++) {
                if (!dfs(graph[i][j])) {
                    return isSafe[i] = 0;
                }
            }
            vis[i] = 0;

            return isSafe[i] = 1;
        };
        vector<int> ans;
        for (short i=0; i<graph.size(); i++) {
            dfs(i);
            if (isSafe[i]) ans.push_back(i);
        }
        
        return ans;
    }
};