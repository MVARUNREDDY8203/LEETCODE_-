class Solution {
public:
    int dp[1001][1001];
    int util(int i, int cnt, int target, vector<int> &nums) {
        if (target == 0) return cnt;
        if (target < 0) return -2;
        if (i >= nums.size()) return -2;

        if (dp[i][target] != -1) return dp[i][target];

        int taken = util(i+1, cnt+1, target - nums[i], nums);
        int not_taken = util(i+1, cnt, target, nums);

        return dp[i][target] = max(taken, not_taken); 
    }
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        memset(dp, -1, sizeof(dp));
        int ans = util(0, 0, target, nums);
        return ans == -2 ? -1 : ans;
    }
};
