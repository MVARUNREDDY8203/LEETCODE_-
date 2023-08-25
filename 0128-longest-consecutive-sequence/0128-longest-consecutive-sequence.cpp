class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size = nums.size();
        if(size <= 1) return size;

        sort(nums.begin(), nums.end());
        int max_con = 1;
        int curr_con = 1;
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i] == nums[i-1]) continue;
            if(nums[i] == nums[i-1]+1) curr_con++;
            else{
                max_con = max(max_con, curr_con);
                curr_con = 1;
            }
        }
        max_con = max(max_con, curr_con);
        return max_con;
    }
};