class Solution {
public:
    int sum_of_digs(int n) {
        if (n < 10) return n;
        return n % 10 + sum_of_digs(n / 10);
    }
    int maximumSum(vector<int>& nums) {
        int n = nums.size();
        // unordered_map<int, priority_queue<int>> sum_digs_to_nums;
        vector<priority_queue<int>> sum_digs_to_nums(100);

        for (int i=0; i<n; i++) {
            sum_digs_to_nums[sum_of_digs(nums[i])].push(nums[i]);
        }

        int ans = -1;
        for (auto i: sum_digs_to_nums) {
            if (i.size() > 1) {
                int curr = i.top();
                i.pop();
                curr += i.top();
                i.pop();

                ans = max(ans, curr);
            }
        }

        return ans;
    }
};