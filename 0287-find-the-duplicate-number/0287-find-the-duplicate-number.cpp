class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        vector<int>freq_map(1e5+1,0);
        for (int i=0; i<nums.size(); i++) {
            freq_map[nums[i]]++;
            if (freq_map[nums[i]] > 1) return nums[i];
        }
        return -1;
    }
};