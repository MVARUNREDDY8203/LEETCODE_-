class Solution {
public:
    struct cmp {
        bool operator()(const vector<int>&a, const vector<int>&b) {
            return a[0] > b[0];
        }
    };
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> min_cost(m, vector<int>(n, INT_MAX));

        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            vector<int> curr = pq.top();
            pq.pop();

            int cost = curr[0], i = curr[1], j = curr[2];
            if (i < 0 || i >= m || j < 0 || j >= n) continue;
            if (min_cost[i][j] <= cost) continue;

            min_cost[i][j] = cost;

            pq.push({cost + !(grid[i][j] == 1), i, j+1});
            pq.push({cost + !(grid[i][j] == 2), i, j-1});
            pq.push({cost + !(grid[i][j] == 3), i+1, j});
            pq.push({cost + !(grid[i][j] == 4), i-1, j});
        }

        return min_cost[m-1][n-1];
    }
};