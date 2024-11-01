class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_map<long long int, int> ump;
        for (int i=0; i<nums.size(); i++) ump[nums[i]]++;
        int curr_streak = 0, n = nums.size(), ans = -1;
        for (int i=0; i<n; i++) {
            long long int curr = nums[i];
            while (ump.count(curr)) {
                ump[curr]--;
                curr_streak++;
                curr = curr * curr;
            }
            ans = max(ans, curr_streak >= 2 ? curr_streak : -1);
            curr_streak = 0;
        }
        return ans;
    }
};