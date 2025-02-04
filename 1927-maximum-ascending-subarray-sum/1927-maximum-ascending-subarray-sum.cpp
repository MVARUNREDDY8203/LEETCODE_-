class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0], curr = nums[0];
        for (int i=1; i<nums.size(); i++) {
            if (nums[i-1] < nums[i]) curr += nums[i];
            else curr = nums[i];

            ans = max(ans, curr);
        }
        return ans;
    }
};