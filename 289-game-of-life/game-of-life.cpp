class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> next_state(m, vector<int>(n, 0));

        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                int live_neighbours = 0;
                next_state[i][j] = board[i][j];
                if (i > 0) {
                    live_neighbours += board[i-1][j];
                    if (j > 0) live_neighbours += board[i-1][j-1];
                    if (j < n-1) live_neighbours += board[i-1][j+1];
                }
                if (i < m-1) {
                    live_neighbours += board[i+1][j];
                    if (j > 0) live_neighbours += board[i+1][j-1];
                    if (j < n-1) live_neighbours += board[i+1][j+1];
                }
                if (j > 0) live_neighbours += board[i][j-1];
                if (j < n-1) live_neighbours += board[i][j+1];

                if (board[i][j] && live_neighbours < 2) next_state[i][j] = 0;
                else if (board[i][j] && live_neighbours > 3) next_state[i][j] = 0;
                else if (!board[i][j] && live_neighbours == 3) next_state[i][j] = 1;

            }
        }
        // board = next_state;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) board[i][j] = next_state[i][j];
        }
    }
};