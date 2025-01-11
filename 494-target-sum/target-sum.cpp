class Solution {
public:
    int dp[20][2000];
    int tar = 0;
    int util(int i, int rem, vector<int>&nums) {
        if (i >= nums.size()) {
            if (rem == tar) return 1;
            return 0;
        }
        
        if (dp[i][rem + 1000] != -1) return dp[i][rem + 1000];
        
        return dp[i][rem + 1000] = util(i+1, rem + nums[i], nums) + util(i+1, rem - nums[i], nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        tar = target;
        memset(dp, -1, sizeof(dp));
        return util(0, 0, nums);
    }
};