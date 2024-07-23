class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(int i, int target, vector<int>& nums) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (target < 0) return;
        if (i >= nums.size()) return;

        temp.push_back(nums[i]);
        dfs(i, target-nums[i], nums);
        temp.pop_back();

        dfs(i+1, target, nums);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        dfs(0, target, nums);
        return ans;
    }
};