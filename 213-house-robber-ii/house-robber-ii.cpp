class Solution {
public:
    int rob(vector<int>& nums) {
        // [rob1, rob2, i, i+1, ... ]
        int rob1 = 0, rob2 = 0, n = nums.size();
        if (n < 2) return nums[0];
        
        for (int i=0; i<n-1; i++) {
            int new_rob2 = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = new_rob2;
        }
        int ans = rob2;
        rob1 = rob2 = 0;
        for (int i=1; i<n; i++) {
            int new_rob2 = max(nums[i] + rob1, rob2);
            rob1 = rob2;
            rob2 = new_rob2;
        }
        return max(ans, rob2);
    }
};