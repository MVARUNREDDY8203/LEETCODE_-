class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int n_by_3 = n/3;
        unordered_map<int, int> ump;
        for (auto i: nums) ump[i]++;
        vector<int> ans;
        for (auto i: ump) {
            if (i.second > n_by_3) ans.emplace_back(i.first);
        }
        return ans;
    }
};