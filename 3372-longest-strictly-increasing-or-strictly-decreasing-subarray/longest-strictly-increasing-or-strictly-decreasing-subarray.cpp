class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int si = 1, sd = 1, n = nums.size(), csi = 1, csd = 1;
        for (int i=1; i<n; i++) {
            if (nums[i-1] > nums[i]) {
                csi = 1;
                csd++;
            }
            else if (nums[i-1] < nums[i]) {
                csd = 1;
                csi++;
            }
            else {
                csi = 1;
                csd = 1;
            }

            si = max(si, csi);
            sd = max(sd, csd);
        }

        return max(si, sd);
    }
};