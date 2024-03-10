class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();

        vector<int> sum_bw_0_and(n, 0);
        sum_bw_0_and[0] = nums[0];
        if (nums[0] == k) ans++;
        for (int i=1; i<n; i++) {
            sum_bw_0_and[i] = sum_bw_0_and[i-1] + nums[i];
            if (sum_bw_0_and[i] == k) ans++;
        }

        
        for (int i=1; i<n; i++) {
            int sum = 0;
            for (int j=i; j<n; j++) {
                sum = sum_bw_0_and[j] - sum_bw_0_and[i-1];
                if (sum == k) ans++;
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     int subarraySum(vector<int>& nums, int k) {
//         int ans = 0, n = nums.size();
//         for (int i=0; i<n; i++) {
//             int sum = 0;
//             for (int j=i; j<n; j++) {
//                 sum += nums[j];
//                 if (sum == k) ans++;
//             }
//         }
//         return ans;
//     }
// };