class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(target-nums[i]) == mp.end()){
                mp[nums[i]] = i;
            }
            else{
                return {mp[target-nums[i]], i};
            }
        }
        return {-1,-1};
    }
};
// vector<int> ans(2,0);
// for(int i=0; i!=nums.size(); i++){
//     for(int j=i+1; j!=nums.size(); j++){
//         if(nums[i]+nums[j]==target){
//             ans[0]=i;
//             ans[1]=j;
//             return ans;
//         }
//     }
// }
///TRY AGAIN BUT WITH MAPS
