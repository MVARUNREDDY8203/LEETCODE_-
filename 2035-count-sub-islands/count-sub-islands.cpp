class Solution {
public:
    int m = 0, n = 0, ans = 0;
    vector<vector<int>> visited;
    int flag = 0;

    void dfs(int i, int j, vector<vector<int>>& g1, vector<vector<int>>& g2) {
        if (i < 0 || j < 0 || i >= m || j >= n || visited[i][j] == 1 || g2[i][j] == 0) return;
        
        visited[i][j] = 1;
        if (g2[i][j] == 1 && g1[i][j] == 0) flag = 1;

        dfs(i+1, j, g1, g2);
        dfs(i-1, j, g1, g2);
        dfs(i, j+1, g1, g2);
        dfs(i, j-1, g1, g2);
    }
    int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
        m = g1.size(), n = g1[0].size();
        visited.resize(m, vector<int>(n, 0));

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                flag = 0;
                if (g2[i][j] && !visited[i][j]) {
                    dfs(i, j, g1, g2);
                    if (!flag) ans++;
                }
            }
        }
        return ans;
    }
};