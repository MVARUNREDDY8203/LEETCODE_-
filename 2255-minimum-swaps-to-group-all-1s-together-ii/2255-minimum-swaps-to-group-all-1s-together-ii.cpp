class Solution {
public:
    int minSwaps(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int n = nums.size(), l = 0, r = 0, ans = INT_MAX, cnt_ones = 0;
        for (auto i: nums) if (i == 1) cnt_ones++;
        int curr = 0;
        while (r < n && r - l + 1 <= cnt_ones) {
            if (nums[r] == 1) curr++;
            r++;
        }
        r--;
        while (r < n + cnt_ones) {
            ans = min(ans, cnt_ones - curr);
            if (nums[++r % n] == 1) curr++;
            if (nums[l++ % n] == 1) curr--;
        }
        return ans;
    }
};