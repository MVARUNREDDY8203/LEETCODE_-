class Solution {
public:
    int dp[201][20001];

    bool cp_util(int i, int target, vector<int>&nums) {
        if (target == 0) return true;
        if (target < 0) return false;
        if (i >= nums.size()) return false;
        if (dp[i][target] != -1) return dp[i][target];

        return dp[i][target] = cp_util(i+1, target-nums[i], nums) || cp_util(i+1, target, nums);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        memset(dp, -1, sizeof(dp));
        for (auto i: nums) sum += i;
        if (sum % 2) return false;
        return cp_util(0, sum/2, nums);
    }
};