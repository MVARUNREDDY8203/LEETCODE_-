class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        vector<int> sig_reached(n+1, 0);
        vector<vector<pair<int, int>>> adj(n+1);
        for (auto vec: times) {
            adj[vec[0]].push_back({vec[1], vec[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        int ans = 0;
        int m = 0;
        while (!pq.empty()) {
            int time = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            if (sig_reached[curr]) continue;

            sig_reached[curr]++;
            m++;
            ans = max(ans, time);
            if (m == n) break;

            for (auto neighbour: adj[curr]) {
                pq.push({time + neighbour.second, neighbour.first});
            }
        }
        for (int i=1; i<=n; i++) if (!sig_reached[i]) return -1;
        return ans;
    }
};