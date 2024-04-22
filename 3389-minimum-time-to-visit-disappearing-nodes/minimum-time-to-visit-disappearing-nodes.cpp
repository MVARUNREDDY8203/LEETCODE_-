class Solution {
private:
    unordered_map<int, vector<pair<int, int>>> graph;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dp;

    unordered_set<int> visited;
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        
        dp.resize(n, -1);

        for (int i=0; i<edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            graph[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }

        
        pq.push({0, 0});
        while (!pq.empty()) {
            pair<int, int>  node = pq.top();
            int dist = node.first;
            int node_val = node.second;
            pq.pop();
            if (!visited.count(node_val) && dist < disappear[node_val]) {
                visited.insert(node_val);
                dp[node_val] = dist;

                for (auto i: graph[node_val]) {
                    int nn_val = i.first;
                    int nn_dist = i.second;
                    if (!visited.count(nn_val)) {
                        pq.push({dist + nn_dist, nn_val});
                    }
                }
            }
        }

        return dp;
    }
};