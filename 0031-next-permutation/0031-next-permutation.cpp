class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size()-1;
        for (i=i; i>0; i--) {
            if (nums[i] > nums[i-1]) break;
        }
        i--;
        if (i < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }

        for (int j=nums.size()-1; j>i; j--) {
            if (nums[j] > nums[i]) {
                swap(nums[i], nums[j]);
                cout<<i;
                reverse(nums.begin()+i+1, nums.end());
                return;
            }
        }
    }
};