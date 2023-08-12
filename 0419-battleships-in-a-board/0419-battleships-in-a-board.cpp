class Solution {
public:
    void mark_as_seen(int x, int y, int p, int q, vector<vector<char>> &board){
        if(x>p || y>q) return;
        if(board[x][y] == '.') return;
        if(board[x][y] == 'X') board[x][y] = '0';
        mark_as_seen(x+1, y, p,q, board);
        mark_as_seen(x, y+1, p,q, board);
    }
    int countBattleships(vector<vector<char>>& board) {
        int p = board.size()-1;
        int q = board[0].size()-1; 
        int total = 0;
        for(int i=0; i<=p; i++){
            for(int j=0; j<=q; j++){
                if(board[i][j] == 'X'){
                    total++;
                    mark_as_seen(i,j, p,q, board);
                }
            }
        }
        return total;
    }
};