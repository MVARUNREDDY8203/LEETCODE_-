class Solution {
public:
    int dp[100001];
    bool two_con(int i, vector<int> &nums) {
        if (i+1 >= nums.size()) return false;
        if (nums[i] == nums[i+1]) return true;
        return false;
    }
    bool three_con(int i, vector<int> &nums) {
        if (i+2 >= nums.size()) return false;

        if (nums[i] == nums[i+1] && nums[i] == nums[i+2]) return true;
        return false;
    }
    bool three_inc(int i, vector<int> &nums) {
        if (i+2 >= nums.size()) return false;

        if (nums[i] == nums[i+1] - 1 && nums[i] == nums[i+2] - 2) return true;
        return false;
    }
    bool util(int i, vector<int> &nums) {
        if (i >= nums.size()) return true;

        if (dp[i] != -1) return dp[i];
        bool ans = 0;
        if (two_con(i, nums)) ans |= util(i+2, nums);
        if (ans) return ans;
        if (three_con(i, nums)) ans |= util(i+3, nums);
        if (ans) return ans;
        if (three_inc(i, nums)) ans |= util(i+3, nums);

        return dp[i] = ans;
    }
    bool validPartition(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        return util(0, nums);
    }
};