class Solution {
public:

    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_set<int> graph;
        int np = 1e7;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int cost = 0;
        for (int i=1; i<points.size(); i++) {
            int x1 = points[0][0], y1 = points[0][1], x2 = points[i][0], y2 = points[i][1];
            int dist = abs(x2-x1) + abs(y2-y1);
            pq.push({dist, 0, i});
        }
        graph.insert(0);
        while (!pq.empty()) {
            int curr_cost = pq.top()[0];
            int prev = pq.top()[1];
            int idx = pq.top()[2];
            pq.pop();
            if (graph.count(idx)) continue;

            cout<<prev<<" "<<idx<<" "<<curr_cost<<endl;
            int x1 = points[idx][0];
            int y1 = points[idx][1];

            graph.insert(idx);

            cost += curr_cost;

            for (int k=0; k<points.size(); k++) {
                if (k == idx) continue;
                if (graph.count(k)) continue;

                int x2 = points[k][0];
                int y2 = points[k][1];
                int dist = abs(x2 - x1) + abs(y2 - y1);

                pq.push({dist, idx, k});
            }
        }
        return cost;
    }   
};