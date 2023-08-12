class Solution {
public:
    int upwo_util(int x, int y, int p, int q, vector<vector<int>> &dp){
        if(x>p || y>q || dp[x][y]==0) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        if(x == p && y == q) return 1;
        dp[x][y] = upwo_util(x+1,y, p,q, dp) + upwo_util(x,y+1, p,q, dp);
        return dp[x][y];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int>(grid[0].size(),-1));
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] == 1) dp[i][j] = 0;
            }
        }
        int p = dp.size()-1;
        int q = dp[0].size()-1;
        return upwo_util(0,0, p, q, dp);
    }
};
































// class Solution {
// public:
//     int uniquePathsWithObstacles(vector<vector<int>>& obsq) {
//         int m = obsq.size();
//         int n = obsq[0].size();
//         vector<vector<long long int>> dp(m, vector<long long int>(n));

//         if(obsq[m-1][n-1] == 1) return 0;
//         if(m == 1 && n==1 && obsq[0][0] == 0) return 1;
//         if(m == 1 && n==1 && obsq[0][0] == 1) return 0;
        
//         for(int i=0; i<m-1; i++){
//             for(int j=0; j<n-1; j++){
//                 if(obsq[i][j] == 1){
//                     dp[i][j] = 0;
//                     obsq[i][j] = 0;
//                 }
//                 else{
//                     obsq[i][j] = -1;
//                 } 
//             }
//         }
//         bool obs = false;
//         bool obs2 = false;
//         for(int i=m-2; i>=0; i--){
//             if(obsq[i][n-1] == 1) obs2 = true;
//             if(obs2) dp[i][n-1] = 0;
//             else dp[i][n-1] = 1;
//         }
//         for(int i=n-2; i>=0; i--){
//             if(obsq[m-1][i] == 1) obs = true;
//             if(obs) dp[m-1][i] = 0;
//             else dp[m-1][i] = 1;
//         }

//         for(int i=m-2; i>=0; i--){
//             for(int j=n-2; j>=0; j--){
//                 if(obsq[i][j]!=0){
//                     dp[i][j] = dp[i+1][j] + dp[i][j+1];
//                 }
//             }
//         }
//         // for(int i=0; i<m; i++){
//         //     for(int j=0; j<n; j++){
//         //         cout<<dp[i][j]<<" ";
//         //     }
//         //     cout<<endl;
//         // }

//         return dp[0][0];
//     }
// };