class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long int sum = 0, n = nums.size();
        for (int i=0; i<n; i++) {
            sum += nums[i];
        }
        int key = sum % p;
        if (key == 0) return 0;

        unordered_map<int, int> ump;
        int ans = nums.size();
        int curr_sum = 0;
        ump[0] = -1;
        for (int i=0; i<n; i++) {
            curr_sum = (curr_sum + nums[i]) % p;
            int needed_sum_mod = ((curr_sum - key) + p) % p;
            if (ump.count(needed_sum_mod)) {
                ans = min(ans, i-ump[needed_sum_mod]);
            }
            ump[curr_sum] = i;
        }
        return ans == n ? -1 : ans;
    }
};