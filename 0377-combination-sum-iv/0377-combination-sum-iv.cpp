class Solution {
public:
    int cs4_util(vector<int> &nums, int rem, vector<int> &dp) {
        if (rem < 0) return 0;
        if (rem == 0) return 1;
        if (dp[rem] != -1) return dp[rem];
        int count = 0;
        for (int i=0; i<nums.size(); i++) {
            count += cs4_util(nums, rem - nums[i], dp);
        }
        dp[rem] = count;
        return count;
    }
    int combinationSum4(vector<int> &nums, int target) {
        vector<int> dp(target+1, -1);
        return cs4_util(nums, target, dp);
    }
};