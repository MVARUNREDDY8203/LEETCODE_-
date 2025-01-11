class Solution {
public:
    int tar = 0;
    map<pair<int, int>, int> dp;
    int util (int i, int rem, vector<int>&nums) {
        if (i >= nums.size()) {
            if (rem == tar) return 1;
            return 0;
        }

        if (dp.count({i, rem})) return dp[{i,rem}];
        
        return dp[{i , rem}] = util(i+1, rem + nums[i], nums) + util(i+1, rem - nums[i], nums);
    }
    int findTargetSumWays(vector<int>& nums, int target) {

        tar = target;
        return util(0, 0, nums);
    }
};