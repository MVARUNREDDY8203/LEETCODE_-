class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long double prefix_prod = 1, suffix_prod = 1, n = nums.size(), ans = INT_MIN;
        for (int i=0; i<n; i++) {
            if (suffix_prod == 0) suffix_prod = 1;
            if (prefix_prod == 0) prefix_prod = 1;

            prefix_prod *= nums[i];
            suffix_prod *= nums[n-1 - i];
            ans = max({ans, prefix_prod, suffix_prod});
        }
        return (int)ans;
    }
};