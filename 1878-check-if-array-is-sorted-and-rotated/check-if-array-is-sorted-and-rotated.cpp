class Solution {
public:
    bool check(vector<int>& nums) {
        char n = nums.size();
        if (nums[0] < nums[n-1]) {
            for (char j=1; j<n; j++) if (nums[j-1] > nums[j]) return false;
            return true;
        }
        
        char deflections = 0;
        for (char j=1; j<n; j++) {
            if (nums[j-1] > nums[j]) deflections++;
            if (deflections > 1) return false;
        }
        
        return true;
    }
};