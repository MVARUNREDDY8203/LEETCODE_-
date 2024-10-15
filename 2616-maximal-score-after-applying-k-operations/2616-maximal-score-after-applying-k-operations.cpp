class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<int> pq;
        for (int i=0; i<n; i++) pq.push(nums[i]);
        long long int ans = 0;
        while (k) {
            int temp = pq.top();
            pq.pop();
            ans += temp;
            pq.push(ceil((double)temp/(double)3));
            k--;
        }
        return ans;
    }
};