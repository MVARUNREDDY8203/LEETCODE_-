class Solution {
public:
    int dp[301][301];

    int util (int l, int r, vector<int>&nums) {
        if (l > r) return 0;

        if (dp[l][r] != -1) return dp[l][r];

        int ans = 0;
        for (int i=l; i<=r; i++) {
            int curr_val = nums[i];
            if (l - 1 >= 0) curr_val *= nums[l-1];
            if (r + 1 < nums.size()) curr_val *= nums[r+1];

            ans = max(ans, curr_val + util(l, i-1, nums) + util(i+1, r, nums));
        }
        return dp[l][r] = ans;
    }
    int maxCoins(vector<int>& nums) {
        vector<int> arr = {1};
        for (auto i: nums) arr.push_back(i);
        arr.push_back(1);
        memset(dp, -1, sizeof(dp));
        return util(0, nums.size()-1, arr);
    }
};