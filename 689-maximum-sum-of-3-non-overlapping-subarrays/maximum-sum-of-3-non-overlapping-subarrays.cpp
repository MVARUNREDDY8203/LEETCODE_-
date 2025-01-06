class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        vector<int> prefix;
        int window = 0;
        for (int i=0; i<k; i++) window += nums[i];
        prefix.push_back(window);
        for (int i=k; i<nums.size(); i++) {
            window += nums[i];
            window -= nums[i-k];
            prefix.push_back(window);
        }

        vector<vector<int>> dp(nums.size(), vector<int>(4, -1));
        function<int(int, int)> util = [&](int i, int rem) -> int {
            if (rem <= 0) return 0;
            if (i >= prefix.size()) return 0;

            if (dp[i][rem] != -1) return dp[i][rem];
            // dont take
            int dont_take = util(i+1, rem);
            int take = prefix[i] + util(i+k, rem-1);

            return dp[i][rem] = max(dont_take, take);
        };
        util(0, 3);

        vector<int> indices;
        function <void(int, int)> dfs = [&](int i, int rem) -> void {
            if (rem <= 0) return;
            if (i >= prefix.size()) return;

            int take = prefix[i] + util(i+k, rem-1);
            int dont_take = util(i+1, rem);

            if (take >= dont_take) {
                indices.push_back(i);
                dfs(i+k, rem-1);
            }
            else {
                dfs(i+1, rem);
            }
        };
        dfs(0, 3);
        
        return indices;
    }
};