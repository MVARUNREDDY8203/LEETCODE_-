class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        for(int i=0; i<n; i++){
            int l = 0;
            int r = n-1;
            while(l<=r){
                swap(matrix[i][l++], matrix[i][r--]);
            }
        }
        return;
    }
};


// class Solution {
// public:
//     void rotate(vector<vector<int>>& matrix) {
//         int n = matrix.size();
//         vector<stack<int>> dp(n);
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 dp[j].push(matrix[i][j]);
//             }
//         }
//         vector<vector<int>> ans(n, vector<int>(n));
//         for(int i=0; i<n; i++){
//             int j=0; 
//             while(!dp[i].empty()){
//                 ans[i][j++] = dp[i].top();
//                 dp[i].pop();
//             }
//         }
        
//         for(int i=0; i<n; i++){
//             for(int j=0; j<n; j++){
//                 matrix[i][j] = ans[i][j];
//             }
//         }
//         return;
//     }
// };