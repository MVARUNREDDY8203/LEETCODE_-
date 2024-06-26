class Solution {
public:
    unordered_map<int, int> ump;
    bool containsDuplicate(vector<int>& nums) {
        for (int i=0; i<nums.size(); i++) {
            ump[nums[i]]++;
            if (ump[nums[i]] >= 2) return true;
        }
        return false;
    }
};