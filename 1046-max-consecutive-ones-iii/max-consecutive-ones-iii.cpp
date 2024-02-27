class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zero_cnt = 0, ans = 0, size = 0, start = 0, end = 0;
        while (end < nums.size()) {
            while (nums[end] == 0 && zero_cnt == k) {
                size--;
                if (nums[start++] == 0) zero_cnt--;
            }
            if (nums[end] == 0) zero_cnt++;
            end++;
            size++;
            ans = max(ans, size);
        }
        return ans;
    }
};