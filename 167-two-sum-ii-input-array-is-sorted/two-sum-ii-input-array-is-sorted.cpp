class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        for (int i=0; i<nums.size(); i++) {
            if (ump.count(target - nums[i])) return {ump[target - nums[i]] + 1, i + 1};
            ump[nums[i]] = i;
        }
        return {0, 0};
    }
};











// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int l=0, r=nums.size()-1;
//         // vector<int> ans; 
//         while(l<r){
//             int sum = nums[l]+nums[r];
//             if(sum == target){
//                 return {l+1, r+1};
//             }
//             else if(sum>target) r--;
//             else l++;
//         }
//         return {l+1, r+1};
//     }
// };