class Solution {
public:
    vector<int> parents;
    int find_parents(int u) {
        if (parents[u] == u) return u;
        return parents[u] = find_parents(parents[u]);
    }
    void union_set(int u, int v) {
        int u_root = find_parents(u);
        int v_root = find_parents(v);

        parents[v_root] = u_root;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        
        for (int i=0; i<=n; i++) parents.push_back(i);
        
        for (int i=0; i<n; i++) {
            if (find_parents(edges[i][0]) == find_parents(edges[i][1])) {
                return edges[i];
            }
            union_set(edges[i][0], edges[i][1]);
        }        
        return {};
    }
};