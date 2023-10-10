class Solution {
public:
    //--------------------BIT MANIPULATION-----------------------//
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();
        for (int i=0; i<32; i++) {
            int count = 0;
            for (auto num: nums) {
                if ((num & (1 << i)) != 0)  count ++; // AND with bitmask, checking if ith bit is set or not
            }

            if (count > n/2) ans |= (1 << i);  //setting the bit in the ans;
        }
        return ans;
    }
};
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         sort(nums.begin(), nums.end());
//         return nums[nums.size()/2];
//     }
// };
// class Solution {
// public:
//     int majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         unordered_map<int, int> ump;
//         for (auto i: nums) ump[i]++;

//         for (auto i: ump) {
//             if (i.second > n/2) return i.first;
//         }
//         return -1;
//     }
// };