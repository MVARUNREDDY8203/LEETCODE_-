class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> ump;
        for (int i=0; i<nums.size(); i++) {
            if (ump.find(nums[i]) != ump.end()) return true;
            ump[nums[i]]++;
        }
        return false;
    }
};



// class Solution {
// public:
//     bool containsDuplicate(vector<int>& nums) {
//         int size = nums.size();

//         sort(nums.begin(), nums.end());
//         for(int i=1; i<size; i++){
//             if(nums[i]== nums[i-1]){
//                 return true;
//             }
//         }
//         return false;
//         // map<int, int> mp;
//         // for(int i=0; i<size; i++){
//         //     mp[nums[i]]++;
//         // }

//         // for(auto &it: mp){
//         //     if(it.second > 1){
//         //         return true;
//         //     }
//         // }
//         // return false;
//     }
// };