class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        int ans = 0;
        for (int i=0; i<m; i++) {
            for (int j=0; j<n; j++) {
                if (nums1[i] == nums2[j]) {
                    if (i > 0 && j > 0) {
                        dp[i][j] = 1 + dp[i-1][j-1];
                    }
                    else dp[i][j] = 1;
                }
                ans = max(ans, dp[i][j]);
                // cout<<dp[i][j]<<" ";
            }
            // cout<<endl;
        }
        return ans;
        
    }
};