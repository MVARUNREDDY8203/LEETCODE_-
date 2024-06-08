class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
        int l = 0, r = nums.size()-1;
        while (l < r) {
            int mid = (l+r)/2;
            if (mid & 1) {
                if (nums[mid] == nums[mid-1]) {
                    l = mid+1;
                }
                else {
                    r = mid;
                }
            }
            else {
                if (nums[mid] == nums[mid+1]) {
                    l = mid+1;
                }
                else {
                    r = mid;
                }
            }
        }
        return nums[l];
    }
};