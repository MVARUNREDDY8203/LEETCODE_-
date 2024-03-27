class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        ios_base::sync_with_stdio(false); cin.tie(NULL);
        sort(nums.begin(), nums.end());
        long long int sum = 0;
        int l = 0, r = 0, n = nums.size(), ans = 0;
        while (r < n) {
            sum += nums[r];
            int size = r - l + 1;
            long long int max_sum = (long long int)size * (long long int)nums[r] - (long long int)sum;
            while (max_sum > k) {
                sum -= nums[l++];
                size = r - l + 1;
                max_sum = (long long int)size * (long long int)nums[r] - (long long int)sum;
            }
            ans = max(ans, r-l+1);
            
            r++;
        }
        return ans;
    }
};