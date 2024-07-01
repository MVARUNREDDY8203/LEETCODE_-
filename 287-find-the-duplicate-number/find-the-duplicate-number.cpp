class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size()-1;
        int size = n+1;
        
        int l = 1, r = n;
        while (l < r) {
            int mid = (l+r)/2;
            int cnt = 0;
            for (int i=0; i<size; i++) {
                if (nums[i] <= mid) cnt++;
            }
            if (cnt > mid) {
                r = mid;
            }
            else l = mid+1;
        }
        return l;
    }
};