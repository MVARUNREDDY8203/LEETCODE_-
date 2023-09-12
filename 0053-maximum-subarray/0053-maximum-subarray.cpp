class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int loc_sum = 0, max_sum = INT_MIN;
        for(auto i: nums){
            loc_sum += i;
            max_sum = max(max_sum, loc_sum);
            if(loc_sum < 0) loc_sum = 0;
        }
        return max_sum;
    }
};