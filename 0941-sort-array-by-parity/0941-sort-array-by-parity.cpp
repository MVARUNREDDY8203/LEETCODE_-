class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans; 
        for (auto i: nums) {
            if (i%2 == 0) ans.emplace_back(i);
        }
        for (auto i: nums) {
            if (i%2 == 1) ans.emplace_back(i);
        }
        return ans;
    }
};