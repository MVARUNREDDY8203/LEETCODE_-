class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int l = 0, r = 0, n = nums.size();
        while (r < n) {
            while (nums[r] >= 1 && nums[r] <= n && nums[r] != r + 1) {
                if (nums[r] == nums[nums[r] - 1]) break;
                swap(nums[r], nums[nums[r] - 1]);
            }
            r++;
        }
        int ans = 0;
        for (int i=0; i<=n; i++) {
            ans = i+1;
            if (i < n && nums[i] != i+1) break;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int firstMissingPositive(vector<int>& nums) {
//         vector<int> dp(1e5+1, 0);
//         for (int i=0; i<nums.size(); i++) {
//             if (nums[i] <= 1e5 && nums[i] > 0) {
//                 dp[nums[i]]++;
//             }
//         }
//         for (int i=1; i<dp.size(); i++) {
//             if (dp[i] == 0) return i;
//         }
//         return 1e5+1;
//     }
// };