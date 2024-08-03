class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        int curr = 0, n = nums.size(), ans = 0;
        ump[0] = 1;
        for (int i=0; i<n; i++) {
            curr += nums[i];
            // if (abs(curr - k))
            ans += ump[curr - k];
            ump[curr]++;
        }
        return ans;
    }
};