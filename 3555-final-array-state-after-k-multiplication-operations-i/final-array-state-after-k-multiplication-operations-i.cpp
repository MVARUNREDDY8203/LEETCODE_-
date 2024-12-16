class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        int n = nums.size();
        for (int i=0; i<k; i++) {
            int nummin = INT_MAX;
            for (int j=0; j<n; j++) {
                nummin = min(nummin, nums[j]);
            }
            for (int j=0; j<n; j++) {
                if (nums[j] == nummin) {
                    nums[j] = nums[j] * multiplier;
                    break;
                }
            }
        }
        return nums;
    }
};