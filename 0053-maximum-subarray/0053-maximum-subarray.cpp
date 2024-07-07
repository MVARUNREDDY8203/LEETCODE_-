class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int ans = nums[0], curr_sum = 0, n = nums.size();
        for (int i=0; i<n; i++) ans = max(ans, nums[i]);
        for (int i=0; i<n; i++) {
            curr_sum += nums[i];
            if (curr_sum < 0) curr_sum = 0;
            else ans = max(ans, curr_sum);
        }
        return ans;
    }
};