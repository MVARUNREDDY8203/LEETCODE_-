class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_set<int> discarded;
        unordered_map<int, vector<int>> x_adj;
        unordered_map<int, vector<int>> y_adj;
        for (int i=0; i<stones.size(); i++) {
            x_adj[stones[i][0]].push_back(i);
            y_adj[stones[i][1]].push_back(i);
        }

        function<void(int)> dfs = [&](int i) -> void {
            if (!discarded.count(i)) {

                discarded.insert(i);
                vector<int> *x_neighbours = &x_adj[stones[i][0]];
                for (int j=0; j<x_neighbours->size(); j++) {
                    int neighbour = (*x_neighbours)[j];
                    dfs(neighbour);
                }
                vector<int> *y_neighbours = &y_adj[stones[i][1]];
                for (int j=0; j<y_neighbours->size(); j++) {
                    int neighbour = (*y_neighbours)[j];
                    dfs(neighbour);
                }
            }
        };
        int cnt = 0;
        for (int i=0; i<stones.size(); i++) {
            if (!discarded.count(i)) {
                dfs(i);
                cnt++;
            }
        }
        return stones.size() - cnt;
    }
};