class Solution {
public:
    bool north(int i, int j, int cnt, char &color, vector<vector<char>>& board) {
        if (i < 0) return false;

        if (color == 'W') {
            if (cnt == 1 && board[i][j] == 'W') return false;
            if (board[i][j] == '.') return false;
            if (cnt >= 2 && board[i][j] == 'W') return true;
            return north(i-1, j, cnt+1, color, board);
        }

        if (cnt == 1 && board[i][j] == 'B') return false;
        if (board[i][j] == '.') return false;
        if (cnt >= 2 && board[i][j] == 'B') return true;
        return north(i-1, j, cnt+1, color, board);
    }
    bool north_east(int i, int j, int cnt, char &color, vector<vector<char>>& board) {
        if (i < 0 || j >= 8) return false;
        
        if (color == 'W') {
            if (cnt == 1 && board[i][j] == 'W') return false;
            if (board[i][j] == '.') return false;
            if (cnt >= 2 && board[i][j] == 'W') return true;
            return north_east(i-1, j+1, cnt+1, color, board);
        }

        if (cnt == 1 && board[i][j] == 'B') return false;
        if (board[i][j] == '.') return false;
        if (cnt >= 2 && board[i][j] == 'B') return true;
        return north_east(i-1, j+1, cnt+1, color, board);
    }
    bool north_west(int i, int j, int cnt, char &color, vector<vector<char>>& board) {
        if (i < 0 || j < 0) return false;
        
        if (color == 'W') {
            if (cnt == 1 && board[i][j] == 'W') return false;
            if (board[i][j] == '.') return false;
            if (cnt >= 2 && board[i][j] == 'W') return true;
            return north_west(i-1, j-1, cnt+1, color, board);
        }

        if (cnt == 1 && board[i][j] == 'B') return false;
        if (board[i][j] == '.') return false;
        if (cnt >= 2 && board[i][j] == 'B') return true;
        return north_west(i-1, j-1, cnt+1, color, board);
    }

    bool south(int i, int j, int cnt, char &color, vector<vector<char>>& board) {
        if (i >= 8) return false;
        
        if (color == 'W') {
            if (cnt == 1 && board[i][j] == 'W') return false;
            if (board[i][j] == '.') return false;
            if (cnt >= 2 && board[i][j] == 'W') return true;
            return south(i+1, j, cnt+1, color, board);
        }

        if (cnt == 1 && board[i][j] == 'B') return false;
        if (board[i][j] == '.') return false;
        if (cnt >= 2 && board[i][j] == 'B') return true;
        return south(i+1, j, cnt+1, color, board);
    }
    bool south_east(int i, int j, int cnt, char &color, vector<vector<char>>& board) {
        if (i >= 8 || j >= 8) return false;
        
        if (color == 'W') {
            if (cnt == 1 && board[i][j] == 'W') return false;
            if (board[i][j] == '.') return false;
            if (cnt >= 2 && board[i][j] == 'W') return true;
            return south_east(i+1, j+1, cnt+1, color, board);
        }

        if (cnt == 1 && board[i][j] == 'B') return false;
        if (board[i][j] == '.') return false;
        if (cnt >= 2 && board[i][j] == 'B') return true;
        return south_east(i+1, j+1, cnt+1, color, board);
    }
    bool south_west(int i, int j, int cnt, char &color, vector<vector<char>>& board) {
        if (i >= 8 || j < 0) return false;
        
        if (color == 'W') {
            if (cnt == 1 && board[i][j] == 'W') return false;
            if (board[i][j] == '.') return false;
            if (cnt >= 2 && board[i][j] == 'W') return true;
            return south_west(i+1, j-1, cnt+1, color, board);
        }

        if (cnt == 1 && board[i][j] == 'B') return false;
        if (board[i][j] == '.') return false;
        if (cnt >= 2 && board[i][j] == 'B') return true;
        return south_west(i+1, j-1, cnt+1, color, board);
    }
    bool east(int i, int j, int cnt, char &color, vector<vector<char>>& board) {
        if (j >= 8) return false;
        
        if (color == 'W') {
            if (cnt == 1 && board[i][j] == 'W') return false;
            if (board[i][j] == '.') return false;
            if (cnt >= 2 && board[i][j] == 'W') return true;
            return east(i, j+1, cnt+1, color, board);
        }

        if (cnt == 1 && board[i][j] == 'B') return false;
        if (board[i][j] == '.') return false;
        if (cnt >= 2 && board[i][j] == 'B') return true;
        return east(i, j+1, cnt+1, color, board);
    }
    bool west(int i, int j, int cnt, char &color, vector<vector<char>>& board) {
        if (j < 0) return false;
        
        if (color == 'W') {
            if (cnt == 1 && board[i][j] == 'W') return false;
            if (board[i][j] == '.') return false;
            if (cnt >= 2 && board[i][j] == 'W') return true;
            return west(i, j-1, cnt+1, color, board);
        }

        if (cnt == 1 && board[i][j] == 'B') return false;
        if (board[i][j] == '.') return false;
        if (cnt >= 2 && board[i][j] == 'B') return true;
        return west(i, j-1, cnt+1, color, board);
    }
    bool checkMove(vector<vector<char>>& board, int rm, int cm, char color) {
        board[rm][cm] = 'V';
        
        int cnt = 0;
        if (north(rm-1, cm, cnt+1, color, board) ||
            south(rm+1, cm, cnt+1, color, board) || 
            west(rm, cm-1, cnt+1, color, board) ||
            east(rm, cm+1, cnt+1, color, board) ||
            north_east(rm-1, cm+1, cnt+1, color, board) ||
            south_east(rm+1, cm+1, cnt+1, color, board) ||
            north_west(rm-1, cm-1, cnt+1, color, board) ||
            south_west(rm+1, cm-1, cnt+1, color, board)) return true;
        // cout<<south_east(rm+1, cm+1, cnt+1, color, board);
        
        return false;
    }
};