class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int loc_sum = 0, max_sum = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            loc_sum += nums[i];
            max_sum = max(max_sum, loc_sum);
            if(loc_sum < 0) loc_sum = 0;
        }
        return max_sum;
    }
};