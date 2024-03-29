class Solution {
private:
public:
    queue<vector<int>> bfs_que;

    void bfs(vector<vector<int>>&graph) {
        int n = graph.size();

        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (graph[i][j] == 1) {
                    bfs_que.push({i-1, j, 2});
                    bfs_que.push({i+1, j, 2});
                    bfs_que.push({i, j+1, 2});
                    bfs_que.push({i, j-1, 2});
                } 
            }
        }

        while (!bfs_que.empty()) {
            int i = bfs_que.front()[0];
            int j = bfs_que.front()[1];
            int dist = bfs_que.front()[2];
            bfs_que.pop();

            if (i < 0 || j < 0 || i >=n || j >= n) continue;

            if (graph[i][j] == 0) {
                graph[i][j] = dist;

                bfs_que.push({i-1, j, dist+1});
                bfs_que.push({i+1, j, dist+1});
                bfs_que.push({i, j-1, dist+1});
                bfs_que.push({i, j+1, dist+1});
            }
        }
    }
    int maxDistance(vector<vector<int>>& graph) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int n = graph.size();

        int ans = -1, land_cnt = 0, water_cnt = 0;
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (graph[i][j] == 1) {
                    land_cnt++;
                }
                else water_cnt++;
            }
        }
        if (!land_cnt || !water_cnt) return -1;

        bfs(graph);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                ans = max(ans, graph[i][j]);
            }
        }
        return ans-1;
    }
};