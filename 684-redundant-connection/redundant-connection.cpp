class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        short n = edges.size();

        vector<vector<short>> graph(n+1, vector<short>(0));
        for (short i=0; i<n; i++) {
            graph[edges[i][0]].push_back(edges[i][1]);
            graph[edges[i][1]].push_back(edges[i][0]);
        }

        bool vis[1001];
        memset(vis, false, sizeof(vis));

        int a = -1, b = -1;
        function<bool(short, short)> dfs_finder = [&](short i, short tar) -> bool {
            if (vis[i]) return false;
            if (i == tar) return true;

            vis[i] = true;
            for (short j=0; j<graph[i].size(); j++) {
                if (i == a && graph[i][j] == b) continue;

                if (dfs_finder(graph[i][j], tar)) return true;
            }
            vis[i] = false;

            return false;
        };

        for (int j=n-1; j>=0; j--) {
            a = edges[j][0];
            b = edges[j][1];
            if (dfs_finder(a, b)) return {a, b};
        }

        return {};
    }
};