class Solution {
public:
    bool util(int i, int j, int m, vector<vector<char>> &board, string &word) {
        if (m >= word.size()) return true;
        if (i >= board.size() || i < 0 || j >= board[0].size() || j < 0) return false;
        if (board[i][j] != word[m]) return false;

        char temp = board[i][j];
        bool present_ahead = false;
        if (board[i][j] == word[m]) {
            board[i][j] = '0';
            present_ahead = (util(i, j+1,m+1, board, word) || util(i+1, j, m+1, board, word) || util(i-1, j, m+1, board, word) || util(i, j-1, m+1, board, word));
        }
        if (present_ahead) return true;
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        bool present = false;
        
        for (int i=0; i<board.size(); i++) {
            for (int j=0; j<board[0].size(); j++) {
                if (board[i][j] == word[0] && util(i, j, 0, board, word)) return true;
            }
        }
        return false;
    }
};


// class Solution {
// public:
//     bool util(int i, int j, int m, vector<vector<char>> &board, string &word) {
//         if (m >= word.size()) return true;
//         if (i >= board.size() && i < 0 && j >= board[0].size() && j < 0) return false;

//         char temp = board[i][j];
//         bool present = false;
//         if (board[i][j] == word[m]) {
//             board[i][j] = '0';
//             present = (util(i, j+1,m+1, board, word) || util(i+1, j, m+1, board, word) || util(i-1, j, m+1, board, word) || util(i, j-1, m+1, board, word));
//         }
//         if (present) return true;
//         board[i][j] = temp;
//         return false;
//     }
//     bool exist(vector<vector<char>>& board, strinag word) {
//         return  util(0, 0, 0, board, word);
//     }
// };