class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void dfs(int i, int target, vector<int> &nums) {
        if (target < 0) return;
        if (target == 0) {
            ans.push_back(temp);
            return;
        }
        if (i >= nums.size()) return;

        temp.push_back(nums[i]);
        dfs(i+1, target-nums[i], nums);
        temp.pop_back();

        int j = i+1;
        while (j < nums.size() && nums[j] == nums[i]) j++;
        dfs(j, target, nums);
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        sort(nums.begin(), nums.end());

        dfs(0, target, nums);
        return ans;
    }
};