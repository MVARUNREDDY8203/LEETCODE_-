class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        unordered_map<int, vector<pair<int, double>>> adj;
        for (int i=0; i<edges.size(); i++) {
            adj[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }
        unordered_set<int> visited;

        priority_queue<pair<int, double>, vector<pair<int, double>>, function<bool(pair<int, double>, pair<int, double>)>> pq(
            [&](pair<int, double> a, pair<int, double> b) {
                return a.second < b.second;
            }
        );

        pq.push({start, 1});
        while (!pq.empty()) {
            int src = pq.top().first;
            double prob = pq.top().second;
            pq.pop();
            cout<<src<<" "<<prob<<endl;

            if (src == end) {
                return prob;
            };

            // if (visited.count(src)) continue;
            visited.insert(src);

            for (auto i: adj[src]) {
                int neighbour = i.first;
                double next_prob = i.second;
                if (visited.count(neighbour)) continue;
                cout<<"n: "<<neighbour<<" "<<prob<<endl; 
                pq.push({neighbour, prob * next_prob});
            }
        }

        return 0;
    }
};