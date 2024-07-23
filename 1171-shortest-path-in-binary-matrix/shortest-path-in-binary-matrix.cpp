class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int m = grid.size(), n = grid[0].size();
        queue<pair<pair<int, int>, int>> que;
        que.push({{0, 0}, 1});

        while (!que.empty()) {
            int i = que.front().first.first;
            int j = que.front().first.second;
            int dist = que.front().second;
            que.pop();

            if (i < 0 || i >= m || j < 0 || j >= n) continue;

            if (grid[i][j] == 0) {
                if (i == m-1 && j == n-1) return dist;
                grid[i][j] = -1;

                que.push({{i-1, j}, dist+1});
                que.push({{i-1, j+1}, dist+1});
                que.push({{i-1, j-1}, dist+1});
                que.push({{i, j+1}, dist+1});
                que.push({{i, j-1}, dist+1});
                que.push({{i+1, j}, dist+1});
                que.push({{i+1, j+1}, dist+1});
                que.push({{i+1, j-1}, dist+1});
            }
        }
        return -1;
    }
};