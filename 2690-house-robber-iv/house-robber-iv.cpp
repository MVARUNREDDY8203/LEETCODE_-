class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int l = 1, r = 1e9, n = nums.size();
        while (l < r) {
            int mid_cap = l + (r - l)/2, cnt = 0;
            for (int i=0; i<n; i++) {
                if (nums[i] <= mid_cap) {
                    cnt++;
                    i++;
                }
            }
            if (cnt >= k) r = mid_cap;
            else l = mid_cap + 1;
        }
        return l;
    }
};