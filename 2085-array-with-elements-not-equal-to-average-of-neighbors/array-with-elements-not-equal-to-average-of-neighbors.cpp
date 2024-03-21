class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 1, n = nums.size();
        while (l < n) {
            swap(nums[l], nums[l-1]);
            l += 2;
        }
        return nums;
    }
};