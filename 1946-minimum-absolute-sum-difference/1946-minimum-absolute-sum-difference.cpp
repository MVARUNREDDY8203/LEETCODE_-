class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        vector<int> n3;
        int n = nums1.size();
        for (int i=0; i<n; i++) n3.push_back(abs(nums1[i] - nums2[i]));
        long long int sum = 0;
        for (auto i: n3) sum += i;
        long long int ans = sum;
        sort(nums1.begin(), nums1.end());
        for (int i=0; i<n; i++) {
            long long int new_diff = sum - abs(n3[i]);
            int j = lower_bound(nums1.begin(), nums1.end(), nums2[i]) - nums1.begin();
            if (j < nums1.size()) {
                ans = min(ans, new_diff + abs(nums2[i] - nums1[j]));
            }
            new_diff = sum - abs(n3[i]);
            if (j > 0) ans = min(ans, new_diff + abs(nums2[i] - nums1[j-1]));
        }

        ans = ans % 1000000007;
        return ans;
    }
};