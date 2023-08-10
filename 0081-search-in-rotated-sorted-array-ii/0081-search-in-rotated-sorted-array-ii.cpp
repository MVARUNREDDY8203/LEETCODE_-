class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums[0] == target) return true;
        if(nums[0] < target){
            for(int i=0; i<nums.size(); i++){
                if(nums[i] == target) return true;
            }
        }else{
            for(int i=nums.size()-1; i>=0; i--){
                if(nums[i] == target) return true;
            }
        }
        return false;
    }
};
// class Solution {
// public:
//     bool search(vector<int>& nums, int target) {
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i] == target) return true;
//         }
//         return false;
//     }
// };