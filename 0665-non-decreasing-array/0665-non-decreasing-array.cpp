class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int size = nums.size();
        if(size <= 2) return true;

        for(int i=0; i<size; i++){
            int temp = nums[i];
            if(i == size-1){
                nums[i] = nums[i-1];
            }else{
                nums[i] = nums[i+1];
            }

            bool possibility = true;

            for(int j=1; j<size; j++){
                if(nums[j] < nums[j-1]){
                    possibility = false;
                    break;
                }
            } 
            if(possibility) return true;  
            nums[i] = temp;         
        }
        return false;
    }
};