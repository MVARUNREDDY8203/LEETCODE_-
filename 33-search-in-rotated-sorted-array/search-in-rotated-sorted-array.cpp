class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l=0, r=nums.size()-1, mid = 0;
        int pivot_idx;
        while (l <= r) {
            mid = (l+r)/2;
            if (nums[l] > nums[r]) {
                if (nums[mid] > nums[r]) {
                    l = mid+1;
                }
                else {
                    r = mid;
                }
            }
            else {
                pivot_idx = l;
                break;
            }
        }
        cout<<pivot_idx;
        
        if (nums[pivot_idx] == target) return pivot_idx;
        if (target > nums[pivot_idx] && nums[nums.size()-1]) {
            l = pivot_idx, r = nums.size()-1;
            while (l < r) {
                mid = (l+r)/2;
                if (nums[mid] == target) return mid;
                if (nums[mid] < target) {
                    l = mid+1;
                }
                else r = mid;
            }
            if (nums[l] == target) return l;
        } 
        l = 0, r = pivot_idx-1;
        while (l < r) {
            mid = (l+r)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) {
                l = mid+1;
            }
            else r = mid;
        }
        return nums[l] == target ? l : -1;
    }
};









// class Solution {
// public:
//     int search(vector<int>& nums, int target) {
//         int n = nums.size(), l = 0, r = n-1, ans = -1;
//         while (l < r) {
//             int mid = (l+r)/2;
//             if (nums[mid] > nums[r]) l = mid+1;
//             else r = mid;
//         }
//         int idx = l, ans_idx = -1;
//         if (target <= nums[n-1]) {
//             ans_idx = lower_bound(nums.begin()+idx , nums.end(), target) - nums.begin();
//             cout<<ans_idx<<endl;
//             if (ans_idx >= n || nums[ans_idx] != target) return -1;
//             return ans_idx;
//         }
//         ans_idx =  lower_bound(nums.begin(), nums.begin()+idx, target) - nums.begin();
//         cout<<ans_idx<<endl;
//         if (ans_idx >= idx || nums[ans_idx] != target) return -1;
//         return ans_idx;
//     }
// };