class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<vector<int>> ans(m,vector<int>(n, m*n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 0) ans[i][j] = 0;
                if(mat[i][j] == 1){
                    if(i>0) ans[i][j] = min(ans[i][j], 1 + ans[i-1][j]);
                    if(j>0) ans[i][j] = min(ans[i][j], 1 + ans[i][j-1]);
                }
            }
        }

        for(int i=m-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                // if(mat[i][j] == 0) ans[i][j] == 0;
                if(mat[i][j] == 1){
                    if(i<m-1) ans[i][j] = min(ans[i][j], 1 + ans[i+1][j]);
                    if(j<n-1) ans[i][j] = min(ans[i][j], 1 + ans[i][j+1]);
                }
            }
        }
        return ans;
    }
};


//  BRRUUUUTE FORCE ! ! !
// vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
//     int m = mat.size();
//     int n = mat[0].size();
//     vector<vector<int>> ans(m, vector<int>(n, INT_MAX));

//     for(int i=0; i<m; i++){
//         for(int j=0; j<n; j++){
//             if(mat[i][j] == 0) ans[i][j] = 0;
//             else{
//                 for(int x=0; x<m; x++){
//                     for(int y=0; y<n; y++){
//                         if(mat[x][y] == 0){
//                             int dist = abs(x-i)+abs(y-j);
//                             ans[i][j] = min(ans[i][j], dist);
//                         }
//                     }
//                 }                
//             }
//         }
//     }
//     return ans;
// }