class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long double max_prod = 1, min_prod = 1, n = nums.size(), ans = nums[0];
        for (auto i: nums) ans = max(ans, (long double)i);
        for (auto curr: nums) {
            long double max_prod_copy = max_prod; 
            max_prod = max((long double)curr, max(max_prod*curr, min_prod*curr));
            min_prod = min((long double)curr, min(max_prod_copy*curr, min_prod*curr));
            cout<<curr<<" "<<max_prod<<" "<<min_prod<<endl;
            ans = max(ans, max_prod);
        }
        cout<<ans;
        return (int)ans;
    }
};