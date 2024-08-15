class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int mod = 1e9 + 7;
        vector<int> sa_sum;
        for (int i=0; i<n; i++) {
            int sum = 0;
            for (int j=i; j<n; j++) {
                sum += nums[j];
                sa_sum.push_back(sum);
            }
        }
        sort(sa_sum.begin(), sa_sum.end());
        int ans = 0;
        // for (auto i: sa_sum) cout<<i<<" ";
        for (int i=left-1; i<right; i++) ans = (ans % mod + sa_sum[i] % mod) % mod;
        return ans;
    }
};