class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int total = 0;
        int size = nums.size();
        if(size == 1){
            return 0;
        }
        for(int i=0; i<size-1; i++){
            for(int j=i+1; j<size; j++){
                if(nums[i] + nums[j] < target) total++;
            }
        }
        return total;
    }
};