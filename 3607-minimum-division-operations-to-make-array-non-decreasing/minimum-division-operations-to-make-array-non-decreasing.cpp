class Solution {
public:
    int util(int i, int n) {
        if (i <= n) return i;
        for (int j=2; j*j <= i && j <= n; j++) if (i % j == 0) return j;
        return -1;
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for (int i=n-2; i>=0; i--) {
            int temp = util(nums[i], nums[i+1]);
            if (temp == -1) return -1;
            if (temp < nums[i]) {
                ans++;
                nums[i] = temp;
            }
        } 
        return ans;
    }
};