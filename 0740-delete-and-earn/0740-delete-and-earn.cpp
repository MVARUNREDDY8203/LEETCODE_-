class Solution {
public:
    unordered_map<int, int> cnt;
    vector<int> dp;
    int dfs(int i, vector<int> &nums) {
        int n = nums.size();
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        int not_pick = 0 + dfs(i+1, nums);
        int pick = nums[i] * cnt[nums[i]];
        if (i+1 < n && nums[i] + 1 == nums[i+1] /* adj element */ ) pick += dfs(i+2, nums);
        else if (i+1 < n) pick += dfs(i+1, nums);

        return dp[i] = max(pick, not_pick);
    }
    int deleteAndEarn(vector<int>& nums) {
        for (auto i: nums) cnt[i]++;
        vector<int> new_nums;
        for (auto i: cnt) new_nums.push_back(i.first);
        sort(new_nums.begin(), new_nums.end());
        dp.resize(new_nums.size()+1, -1);
        return dfs(0, new_nums);
    }
};