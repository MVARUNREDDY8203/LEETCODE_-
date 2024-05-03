class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
        long long int n = nums.size(), prev_cnt = 0, total_cnt = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] == 0) {
                total_cnt += prev_cnt + 1;
            }
            if (nums[i] == 0) {
                prev_cnt++;
            }
            else {
                prev_cnt = 0;
            }
        }
        return total_cnt;
    }
};