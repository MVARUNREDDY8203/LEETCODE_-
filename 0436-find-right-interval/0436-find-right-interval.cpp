class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& nums) {
        for (int i=0; i<nums.size(); i++) {
            nums[i].push_back(i);
        }
        sort (nums.begin(), nums.end(), [] (vector<int>&a, vector<int> &b) {
            return a[0] < b[0];
        });
        vector<int> ans(nums.size(), -1);

        for (int i=0; i<nums.size(); i++) {
            int idx = upper_bound (nums.begin(), nums.end(), nums[i][1], [] (int val, vector<int> &a) {
                return val <= a[0];
            }) - nums.begin();
            ans[nums[i][2]] = (idx >= nums.size() ? -1 : nums[idx][2]);
        }
        return ans;
    }
};