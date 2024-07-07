class Solution {
public:
    int util(int i, vector<int> &nums, vector<int> &dp) {
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int taken = nums[i] + util(i+2, nums, dp);
        int not_taken = util(i+1, nums, dp);
        return dp[i] = max(taken, not_taken);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return util(0, nums, dp);
    }
};