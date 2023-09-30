class Solution {
public:

//     int snakesAndLadders(vector<vector<int>>& board) {
//     int n = board.size();
//     vector<int> snl(n * n + 1, -1);
//     bool leftToRight = true;
//     int num = 1;

//     for (int i = n - 1; i >= 0; i--) {
//         if (leftToRight) {
//             for (int j = 0; j < n; j++) {
//                 snl[num] = board[i][j];
//                 num++;
//             }
//         } else {
//             for (int j = n - 1; j >= 0; j--) {
//                 snl[num] = board[i][j];
//                 num++;
//             }
//         }
//         leftToRight = !leftToRight;
//     }

//     queue<int> que;
//     vector<int> steps(n * n + 1, -1);
//     que.push(1);
//     steps[1] = 0;

//     while (!que.empty()) {
//         int curr = que.front();
//         que.pop();

//         if (curr == n * n) {
//             return steps[curr];
//         }

//         for (int i = 1; i <= 6; i++) {
//             int next = curr + i;

//             if (next <= n * n && snl[next] != -1) {
//                 next = snl[next];
//             }

//             if (next <= n * n && steps[next] == -1) {
//                 steps[next] = steps[curr] + 1;
//                 que.push(next);
//             }
//         }
//     }

//     return -1;
// }

    queue<int> que;
    int bfs (vector<int> &snl, int n) {
        if (snl[n*n] != -1) return -1;

        que.push(1);
        vector<int> steps(n*n + 1 , -1);
        steps[1] = 0;

        while (!que.empty()) {
            int curr = que.front();
            if (curr == n*n) return snl[n*n];
            que.pop();

            for (int i=1; i<=6; i++) {
                int next = snl[min(curr + i, n*n)];
                next = (next == -1 ? min(curr + i, n*n) : next);
                
                if (steps[next] == -1) {    // if not visited then update
                    steps[next] = steps[curr] + 1; 
                    if (next == n*n) return steps[next];
                    que.push(next);
                }
            }
        }
        return -1;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        vector<int> snl;
        int n = board.size();
        bool left_to_right = true;
        snl.push_back(0);
        
        for (int i=n-1; i>=0; i--) {
            if (left_to_right) for (int j=0; j<n; j++) snl.emplace_back(board[i][j]);
            else for (int j=n-1; j>=0; j--) snl.emplace_back(board[i][j]);
            left_to_right = !left_to_right;
        }

        return bfs(snl, n);
    }
};