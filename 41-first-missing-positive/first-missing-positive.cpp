class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> dp(1e5+1, 0);
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] <= 1e5 && nums[i] > 0) {
                dp[nums[i]]++;
            }
        }
        for (int i=1; i<dp.size(); i++) {
            if (dp[i] == 0) return i;
        }
        return 1e5+1;
    }
};