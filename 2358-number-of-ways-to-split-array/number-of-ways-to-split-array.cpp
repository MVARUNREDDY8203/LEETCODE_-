class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int sum = 0, n = nums.size();
        for (int i=0; i<n; i++) {
            sum += nums[i];
        }
        long long int ans = 0, sum2 = 0;
        for (int i=0; i<n-1; i++) {
            sum2 += nums[i];
            sum -= nums[i];

            if (sum2 >= sum) ans++;
        }
        return ans;
    }
};