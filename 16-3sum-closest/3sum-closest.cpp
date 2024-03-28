class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int min_diff = INT_MAX, n = nums.size(), ans = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());

        for (int i=0; i <= n-3; i++) {
            int sum = nums[i];
            int l = i+1, r = n-1;
            while (l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if (abs(sum - target) < min_diff) {
                    min_diff = abs(sum - target);
                    ans = sum;
                }
                if (sum > target) {
                    r--;
                }
                else {
                    l++;
                }
            }
        }
        return ans;
    }
};