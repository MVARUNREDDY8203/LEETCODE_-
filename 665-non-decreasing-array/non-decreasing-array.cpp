class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0, cnt2 = 0, prev = -1e5-2, n = nums.size();
        for (int i=0; i<n; i++) {
            if (nums[i] < prev) cnt++;
            prev = max(prev, nums[i]);
        }
        prev = 1e5+2;
        for (int i=n-1; i>=0; i--) {
            if (nums[i] > prev) cnt2++;
            prev = min(prev, nums[i]);
        }
        if (cnt > 1 && cnt2 > 1) return false;
        return true;
    }
};
