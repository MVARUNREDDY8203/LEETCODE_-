class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() == 1) return true;
        bool asc = true, desc = true;
        for (int i=1; i<nums.size(); i++) {
            if (nums[i] < nums[i-1]) {
                asc = false; 
            }
            if (nums[i] > nums[i-1]) {
                desc = false; 
            }
        }
        return asc || desc;        
    }
};
    // bool isMonotonic(vector<int>& nums) {
    //     // vector<int> nums2 = nums;
    //     // sort(nums.begin(), nums.end());
    //     // bool asc = true;
    //     // bool desc = true;
    //     // for (int i=0; i<nums.size(); i++) {
    //     //     if (nums2[i] != nums[i]) {
    //     //         asc = false;
    //     //     }
    //     //     if (nums2[i] != nums[nums.size()-1-i]) {
    //     //         desc = false;
    //     //     }
    //     // }
        
    //     // return asc || desc;
    // }