class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        for (int i=0; i<n; i++) {
            for (int j=(i+1)%n; j<i+n; j++) {
                if (nums[j % n] > nums[i]) {
                    ans[i] = nums[j % n];
                    break;
                }
            }
        }
        return ans;
    }
};