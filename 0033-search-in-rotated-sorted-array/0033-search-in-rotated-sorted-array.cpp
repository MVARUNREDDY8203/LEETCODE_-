class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), l = 0, r = n-1, ans = -1;
        while (l < r) {
            int mid = (l+r)/2;
            if (nums[mid] > nums[r]) l = mid+1;
            else r = mid;
        }
        int idx = l, ans_idx = -1;
        if (target <= nums[n-1]) {
            ans_idx = lower_bound(nums.begin()+idx , nums.end(), target) - nums.begin();
            cout<<ans_idx<<endl;
            if (ans_idx >= n || nums[ans_idx] != target) return -1;
            return ans_idx;
        }
        ans_idx =  lower_bound(nums.begin(), nums.begin()+idx, target) - nums.begin();
        cout<<ans_idx<<endl;
        if (ans_idx >= idx || nums[ans_idx] != target) return -1;
        return ans_idx;
    }
};