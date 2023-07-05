class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev = 0, curr=0, longest=0;
        bool ones = true;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == 0){
                ones = false;
                break;
            } 
        }
        if(ones) return nums.size()-1;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==0){
                longest = max(longest, prev+curr);
                prev = curr;
                curr = 0;
            }else curr++;
        }
        return max(longest, prev+curr);
        
    }
};