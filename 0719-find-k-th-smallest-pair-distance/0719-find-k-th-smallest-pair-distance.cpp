class Solution {
public:
    bool enough(vector<int>&nums, int k, int dist) {
        int cnt = 0, i = 0, j = 0, n = nums.size();
        while (i < n || j < n) {
            while (j < n && nums[j] - nums[i] <= dist) j++;
            cnt += (j-1)-i;
            i++;
        }
        return cnt >= k;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), l = 0, r = nums[n-1] - nums[0];
        while (l < r) {
            int mid = l + (r-l)/2;
            if (enough(nums, k, mid)) {
                r = mid;
            }
            else l = mid+1;
        }
        return l;
    }
};