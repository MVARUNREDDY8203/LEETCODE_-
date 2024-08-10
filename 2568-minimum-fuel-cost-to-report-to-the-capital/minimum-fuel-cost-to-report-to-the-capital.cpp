class Solution {
public:
    vector<vector<int>> adj;
    int visited[100001];
    long long int seat_limit = 0;
    long long int ans = 0;

    int dfs(int i) {
        int seats_incoming = 0;
        if (visited[i]) return 0;

        visited[i] = 1;
        for (int j=0; j<adj[i].size(); j++) {
            if (!visited[adj[i][j]]) {
                int seats_incoming_for_j = dfs(adj[i][j]);
                ans += ceil((double)seats_incoming_for_j / (double)seat_limit);
                seats_incoming += seats_incoming_for_j;
            }
        }
        // visited[i] = 0;

        return seats_incoming + 1;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int n = roads.size();
        adj.resize(n+10, vector<int>(0, {}));
        seat_limit = seats;
        memset(visited, 0, sizeof(visited));

        for (int i=0; i<roads.size(); i++) {
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]);
        }

        int all_incoming_seats = dfs(0);

        return ans;
    }
};