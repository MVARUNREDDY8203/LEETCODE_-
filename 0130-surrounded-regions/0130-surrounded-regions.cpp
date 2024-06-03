class Solution {
public:
    int m = 0, n = 0;
    vector<vector<int>> visited;
    void dfs_marker(int i, int j, vector<vector<char>>&board) {
        if (i < 0 || j < 0 || i >= m || j >= n) return;
        if (visited[i][j]) return;

        if (board[i][j] != 'O') return;
        board[i][j] = 'Z';
        visited[i][j] = 1;
        dfs_marker(i+1, j, board);
        dfs_marker(i-1, j, board);
        dfs_marker(i, j+1, board);
        dfs_marker(i, j-1, board);
    }
    void solve(vector<vector<char>>& board) {
        m = board.size(), n = board[0].size();
        visited.resize(m, vector<int>(n, 0));
        for (int i=0; i<n; i++) dfs_marker(0, i, board);
        for (int i=0; i<n; i++) dfs_marker(m-1, i, board);
        for (int i=0; i<m; i++) dfs_marker(i, 0, board);
        for (int i=0; i<m; i++) dfs_marker(i, n-1, board);

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                if (board[i][j] == 'Z') board[i][j] = 'O';
            }
        }
    }
};