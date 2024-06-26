class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int l = 0, r = nums.size()-1, mid = (l+r)/2;

        while (l < r-1) {
            mid = (l+r)/2;
            if (nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]) return mid;
            if (nums[mid] > nums[mid-1] && nums[mid] < nums[mid+1]) l = mid;
            else r = mid;
        }
        return mid;
    }
};