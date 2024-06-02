class Solution {
public:
    queue<vector<int>> que;
    vector<vector<int>> visited;
    vector<vector<int>> dist_map;

    void bfs(int p, int q, int a, vector<vector<int>> &grid) {  // p, q is the infection starter node, a is the u_id of the nth rotten apple, used to account for the nth bfs/visited map
        int m = grid.size(), n = grid[0].size();
        que.push({p-1, q, 1}); // infection spreads 4d way from the root/rotten apple
        que.push({p+1, q, 1});
        que.push({p, q-1, 1});
        que.push({p, q+1, 1});

        while (!que.empty()) {
            int i = que.front()[0];
            int j = que.front()[1];
            int dist = que.front()[2];
            que.pop();
            
            if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1 || visited[i][j] == a) continue; // infection cannot spread out_of_bounds|to an apple that is not fresh|if it has already been visited by the ath infection

            dist_map[i][j] = min(dist_map[i][j], dist);     // taking min dist/time of infection spread 
            visited[i][j] = a;

            que.push({i, j+1, dist+1});     // infection spread;
            que.push({i, j-1, dist+1});
            que.push({i+1, j, dist+1});
            que.push({i-1, j, dist+1});
        }
    }
    int orangesRotting(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int m = grid.size(), n = grid[0].size();
        dist_map.resize(m, vector<int>(n, INT_MAX)); // to account the distances/time of the infection spread
        visited.resize(m, vector<int>(n, -1));      // to account if the apple is visited or not globally accessible

        int a = 1;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 2) {
                    bfs(i, j, a++, grid);  // if the apple is rotten, we call bfs to spread infection
                }
            }
        }

        int ans = -1; // default -1 value initialized
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (grid[i][j] == 1) { 
                    if (visited[i][j] == -1) return -1; // if the apple is fresh and is never visited return -1
                    ans = max(ans, dist_map[i][j]); // if the apple was originally fresh, we take the maximum of the dist_map[i][j] as the ans as this is the last apple to get infection
                }
            }
        }
        return ans == -1 ? 0 : ans; // if ans is not updated from -1, this means there are no 1s in the array, meaning no infection would spread and time = 0
    }
};