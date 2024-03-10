class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();

        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        for (int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }

        unordered_map<int, int> ump;

        for (int i=0; i<n; i++) {
            if (prefix[i] == k) ans++;
            ans+= ump[prefix[i]-k];
            ump[prefix[i]]++;
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