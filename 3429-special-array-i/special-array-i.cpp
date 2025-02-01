class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        char parity = nums[0] % 2;
        for (int i=1; i<nums.size(); i++) {
            if (i % 2) {
                if (nums[i] % 2 == parity) return false;
            } else {
                if (nums[i] % 2 != parity) return false;
            }
        }
        return true;
    }  
};