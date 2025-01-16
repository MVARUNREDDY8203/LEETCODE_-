class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        int ans = 0;
        if (n2 % 2 == 1) {
            // n2 is odd => every number in nums1 xored will result in nums1[i];
            for (int i=0; i<n1; i++) {
                ans = ans ^ nums1[i];
            }
        }
        if (n1 % 2 == 1) {
            for (int i=0; i<n2; i++) {
                ans = ans ^ nums2[i];
            }
        }
        return ans;
    }
};