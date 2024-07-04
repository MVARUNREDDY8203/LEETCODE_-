class Solution {
public:
    bool check(vector<int> &nums, int mid_val, int k) {
        int sum = 0, cnt = 1;
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] + sum <= mid_val) {
                sum += nums[i];
            }
            else {
                cnt++;
                sum = nums[i];
            }
        }

        return cnt<=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size(), s = 0, max_val = nums[0], ans = INT_MAX;
        for (int i=0; i<n; i++){ 
            s += nums[i];
            max_val = max(max_val, nums[i]);
        }

        int l = max_val, r = s;
        while (l <= r) {
            int mid = l + (r-l)/2;
            
            if (check(nums, mid, k)) {
                ans = min(ans, mid);
                r = mid-1;
            }
            else l = mid+1;
        }

        return ans;
    }
};