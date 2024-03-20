class Solution {
private:
int mod = 1e9+7;
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = 0;

        vector<int> pow2(nums.size()+2, 1);
        for (int i=1; i<=nums.size(); i++) pow2[i] =  (2 * pow2[i-1]) % mod;

        int l = 0, r = nums.size()-1;
        while (l <= r) {
            if (nums[l] + nums[r] > target) {
                r--;
            }
            else {
                ans = (ans + pow2[r - l++]) % mod;
            }
        }
        return ans;
    }
};