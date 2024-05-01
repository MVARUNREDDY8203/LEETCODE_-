class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> ump;

        int sum = 0;
        ump[0] = -1;
        for (int i=0; i<n; i++) {
            sum += nums[i];
            if (ump.count(sum % k)) {
                if (i - ump[sum % k] >= 2) return true;
            }
            else ump[sum % k] = i;
        }
        return false;
    }
};