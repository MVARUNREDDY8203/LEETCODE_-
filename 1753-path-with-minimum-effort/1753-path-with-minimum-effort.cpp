class Solution {
public:
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int m = heights.size(), n = heights[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            int diff = pq.top()[0];
            int i = pq.top()[1];
            int j = pq.top()[2];
            // cout<<i<<" "<<j<<" "<<diff<<endl;
            pq.pop();

            if (i < 0 || i >= m || j < 0 || j >= n) continue;
            if (heights[i][j] == -1) continue;
            if (i == m-1 && j == n-1) return diff;

            if (i-1 >= 0) pq.push({max(diff, abs(heights[i][j] - heights[i-1][j])), i-1, j});
            if (i+1 < m) pq.push({max(diff, abs(heights[i][j] - heights[i+1][j])), i+1, j});
            if (j+1 < n) pq.push({max(diff, abs(heights[i][j] - heights[i][j+1])), i, j+1});
            if (j-1 >= 0) pq.push({max(diff, abs(heights[i][j] - heights[i][j-1])), i, j-1});

            heights[i][j] = -1;
        }

        return 0;
    }
};