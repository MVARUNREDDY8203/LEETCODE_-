class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<stack<int>> dp(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                dp[j].push(matrix[i][j]);
            }
        }
        vector<vector<int>> ans(n, vector<int>(n));
        for(int i=0; i<n; i++){
            int j=0; 
            while(!dp[i].empty()){
                ans[i][j++] = dp[i].top();
                dp[i].pop();
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                matrix[i][j] = ans[i][j];
            }
        }
        return;
    }
};