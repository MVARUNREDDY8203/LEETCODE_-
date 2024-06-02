class Solution {
public:
    int m = 0, n = 0;
    vector<vector<int>> visited, ocean;
    queue<vector<int>> que;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        visited.resize(m, vector<int>(n, 0));
        ocean.resize(m, vector<int>(n, 0));

        for (int i=0; i<n; i++) que.push({0, i, heights[0][i]});
        for (int i=0; i<m; i++) que.push({i, 0, heights[i][0]});

        while (!que.empty()) {
            int i = que.front()[0];
            int j = que.front()[1];
            int prev = que.front()[2];
            que.pop();

            if (i < 0 || i >= m || j < 0 || j >= n || prev > heights[i][j] || visited[i][j]) continue;
            ocean[i][j]++;
            visited[i][j] = 1;

            que.push({i+1, j, heights[i][j]});
            que.push({i-1, j, heights[i][j]});
            que.push({i, j+1, heights[i][j]});
            que.push({i, j-1, heights[i][j]});
        }

        // visited.resize(m, vector<int>(n, 0));
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                visited[i][j] = 0;
            }
        }
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cout<<visited[i][j]<<" ";
                // if (ocean[i][j] == 2) ans.push_back({i, j});
            }
            cout<<endl;
        }
            cout<<endl;

        for (int i=0; i<n; i++) que.push({m-1, i, heights[m-1][i]});
        for (int i=0; i<m; i++) que.push({i, n-1, heights[i][n-1]});

        while (!que.empty()) {
            int i = que.front()[0];
            int j = que.front()[1];
            int prev = que.front()[2];
            que.pop();

            if (i < 0 || i >= m || j < 0 || j >= n || prev > heights[i][j] || visited[i][j]) continue;
            ocean[i][j]++;
            visited[i][j] = 1;

            que.push({i+1, j, heights[i][j]});
            que.push({i-1, j, heights[i][j]});
            que.push({i, j+1, heights[i][j]});
            que.push({i, j-1, heights[i][j]});
        }

        vector<vector<int>> ans;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                cout<<ocean[i][j]<<" ";
                if (ocean[i][j] == 2) ans.push_back({i, j});
            }
            cout<<endl;
        }
        return ans;
    }
};