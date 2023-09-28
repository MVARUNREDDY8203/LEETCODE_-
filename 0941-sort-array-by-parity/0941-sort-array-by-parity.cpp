class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int l = 0;
        int r = nums.size()-1;
        while (l <= r) {
            if (nums[l] % 2 == 1) swap(nums[l], nums[r--]);
            else l++;
        }
        return nums;
    }
};
// vector<int> sortArrayByParity(vector<int>& nums) {
//     vector<int> ans; 
//     for (auto i: nums) {
//         if (i%2 == 0) ans.emplace_back(i);
//     }
//     for (auto i: nums) {
//         if (i%2 == 1) ans.emplace_back(i);
//     }
//     return ans;
// }