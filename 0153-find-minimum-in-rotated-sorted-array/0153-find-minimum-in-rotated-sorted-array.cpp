class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n-1;
        int ans = INT_MAX;
        while (l < r) {
            int mid = (l+r)/2;
            if (nums[mid] <= nums[r]) {
                r = mid;
                // ans = min(nums[mid], ans);
            }else {
                l = mid + 1;
            }
            // else return min(ans, nums[mid]);
        }
        return nums[l];
    }
};