class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> sig_reached(n+1, 0);
        map<pair<int, int>, int> edge;
        for (auto vec: times) {
            int src = vec[0], dest = vec[1], time = vec[2];
            edge[{src, dest}] = time;
        }

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, k});
        int ans = 0;
        while (!pq.empty()) {
            int time = pq.top()[0];
            int prev = pq.top()[1];
            int curr = pq.top()[2];
            cout<<prev<<" "<<curr<<" "<<time<<endl;
            pq.pop();

            if (sig_reached[curr]) continue;

            sig_reached[curr]++;
            ans = max(ans, time);

            for (int k=0; k<=n; k++) {
                if (edge.count({curr, k})) {
                    pq.push({time + edge[{curr, k}], curr, k});
                }
            }
        }
        for (int i=1; i<=n; i++) if (!sig_reached[i]) return -1;
        return ans;
    }
};