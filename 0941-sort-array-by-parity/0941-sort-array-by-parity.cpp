class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> even;
        for (auto i: nums) {
            if (i%2 == 0) even.emplace_back(i);
        }
        vector<int> ans;
        for (auto i: even) {
            ans.emplace_back(i);
        }
        for (auto i: nums) {
            if (i%2 == 1) ans.emplace_back(i);
        }
        return ans;
    }
};