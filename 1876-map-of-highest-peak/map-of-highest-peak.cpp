class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));

        queue<pair<int, pair<int, int>>> que;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (isWater[i][j]) {
                    que.push({0, {i, j}});
                }
            }
        }

        while (!que.empty()) {
            int curr_i = que.front().second.first, curr_j = que.front().second.second, val = que.front().first;
            que.pop();

            if (curr_i < 0 || curr_i >= m || curr_j < 0 || curr_j >= n || ans[curr_i][curr_j] != -1) continue;
            if (!isWater[curr_i][curr_j]) {
                ans[curr_i][curr_j] = val;
            }
            else ans[curr_i][curr_j] = 0;

            que.push({ans[curr_i][curr_j] + 1, {curr_i + 1, curr_j}});
            que.push({ans[curr_i][curr_j] + 1, {curr_i - 1, curr_j}});
            que.push({ans[curr_i][curr_j] + 1, {curr_i, curr_j + 1}});
            que.push({ans[curr_i][curr_j] + 1, {curr_i, curr_j - 1}});
        }

        return ans;
    }
};