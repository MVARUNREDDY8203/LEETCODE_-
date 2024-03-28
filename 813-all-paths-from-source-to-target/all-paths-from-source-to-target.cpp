class Solution {
public:
    vector<vector<int>> ans;
    void util(int i, vector<vector<int>> &graph, vector<int> &path) {
        if (i >= graph.size()-1) {
            ans.push_back(path);
            return;
        }
        for (int j=0; j<graph[i].size(); j++) {
            path.push_back(graph[i][j]);
            util(graph[i][j], graph, path);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        vector<int> path = {0};
        util(0, graph, path);
        return ans;
    }
};