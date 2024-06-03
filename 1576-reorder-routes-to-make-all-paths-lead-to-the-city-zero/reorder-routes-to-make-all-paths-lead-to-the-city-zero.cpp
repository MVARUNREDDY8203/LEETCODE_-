class Solution {
public:
    
    int minReorder(int n, vector<vector<int>>& connections) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        vector<vector<vector<int>>> adj(n);
        for (auto i: connections) {
            adj[i[0]].push_back({i[1], 1});
            adj[i[1]].push_back({i[0], 0});
        }

        stack<int> stk;
        int cnt = 0;
        stk.push(0);
        set<int> visited;
        while (!stk.empty()) {
            int parent = stk.top();
            stk.pop();
            for (auto i: adj[parent]) {
                if (!visited.count(i[0])) {
                    int child = i[0];
                    int sign = i[1];
                    cnt += sign;
                    stk.push(child);
                }
            }
            visited.insert(parent);
        }
        return cnt;
    }
};