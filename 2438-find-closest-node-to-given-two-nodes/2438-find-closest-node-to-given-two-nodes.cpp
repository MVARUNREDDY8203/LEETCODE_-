class Solution {
public:
    vector<int> dfs1;
    vector<int> dfs2;
    void util(int i, int dist, vector<int> &dfs_i, vector<int>&edges) {
        if (edges[i] == -2) return;
        dfs_i[i] = dist;
        if (edges[i] == -1) return;
        
        int temp = edges[i];
        edges[i] = -2;
        util(temp, dist+1, dfs_i, edges);
        edges[i] = temp;
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int n = edges.size();
        dfs1.resize(n+1, INT_MAX);
        dfs2.resize(n+1, INT_MAX);

        util(node1, 0, dfs1, edges);
        util(node2, 0, dfs2, edges);

        int ans_val = INT_MAX;
        int ans_idx = -1;

        // for (int i =0; i<n; i++) cout<<dfs1[i]<<" "<<dfs2[i]<<endl;
        for (int i=0; i<n; i++) {
            if (max(dfs1[i], dfs2[i]) < ans_val) {
                ans_val = max(dfs1[i], dfs2[i]);
                ans_idx = i;
            }
        }
        return ans_idx;
    }
};