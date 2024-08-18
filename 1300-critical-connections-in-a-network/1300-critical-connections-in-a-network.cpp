class Solution {
public:
    vector<vector<int>> adj;
    vector<int> disc;
    vector<vector<int>> critical_conns;
    vector<int> processed;
    int dfs(int i, int depth) {
        if (disc[i] < depth) return disc[i];
        
        disc[i] = depth;
        int min_depth = depth;
        for (int j=0; j<adj[i].size(); j++) {
            if (disc[adj[i][j]] != depth-1 && processed[adj[i][j]] == 0) {
                // we dont want to go back to the parent right away
                int curr_min_depth = dfs(adj[i][j], depth+1);
                if (curr_min_depth > depth) {
                    // bridging edge
                    critical_conns.push_back({i, adj[i][j]});
                } 
                min_depth = min(min_depth, curr_min_depth);
            }
        }

        processed[i] = 1;
        return min_depth;
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        adj.resize(n+1, vector<int>(0, {}));
        disc.resize(n+1, INT_MAX);
        processed.resize(n+1, 0);
        for (auto i: connections) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        dfs(0, 1);
        return critical_conns;
    }   
};