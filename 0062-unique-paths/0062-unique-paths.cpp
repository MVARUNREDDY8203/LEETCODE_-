class Solution {
public:
    int uniquePathUtil(int x, int y, int m, int n, vector<vector<int>> &dp){
        for(int i=m; i>=0; i--){
            for(int j=n; j>=0; j--){
                if(i == m || j == n){
                    dp[i][j] = 1;
                    continue;
                }
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
        // if(x > m || y > n){
        //     return 0;
        // }
        // if(x == m && y == n){
        //     return 1;
        // }
        // if(x == m){
        //     if(dp[x][y] == 0){
        //         dp[x][y] = uniquePathUtil(x, y+1, m, n, dp);
        //     }
        //     return dp[x][y];
        // }
        // if(y == n){
        //     if(dp[x][y] == 0){
        //         dp[x][y] = uniquePathUtil(x+1, y, m, n, dp);
        //     }
        //     return dp[x][y];
        // }
        // if(dp[x][y] == 0){
        //     dp[x][y] = uniquePathUtil(x+1, y, m, n, dp) + uniquePathUtil(x, y+1, m, n, dp);
        // }
        // return dp[x][y];
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        return uniquePathUtil(0,0,m-1,n-1, dp);
    }
};