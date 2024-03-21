class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        for (int i=1; i<nums.size()-1; i++) {
            if (nums[i]*2 == nums[i-1] + nums[i+1]) swap(nums[i], nums[i+1]);
        }

        for (int i=nums.size()-2; i>=1; i--) {
            if (nums[i]*2 == nums[i-1] + nums[i+1]) swap(nums[i], nums[i-1]);
        }
        return nums;
    }
};

// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         int l = 1, n = nums.size();
//         while (l < n) {
//             swap(nums[l], nums[l-1]);
//             l += 2;
//         }
//         return nums;
//     }
// };