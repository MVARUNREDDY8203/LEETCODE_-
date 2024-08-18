class Solution {
public:
    
    int smallestDistancePair(vector<int>& nums, int k) {
        function<int(vector<int>, int)> util = [&](vector<int> nums, int diff) -> int {
            int n = nums.size();
            int cnt = 0, slow = 0, fast = 0;
            while (slow < n || fast < n) {
                while (fast < n && nums[fast] - nums[slow] <= diff) {
                    fast++;
                }
                cnt += fast-1 - slow;
                slow++;
            }
            return cnt;
        };
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int r = nums[n-1] - nums[0];
        int l = 0;
        while (l < r) {
            int mid = l + (r-l)/2;
            int curr_cnt = util(nums, mid);
            if (curr_cnt >= k) r = mid;
            else l = mid+1;
        }
        return l;
    }
};