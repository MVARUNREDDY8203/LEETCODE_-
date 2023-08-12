class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();

        if(size == 2){
            int temp = nums[0];
            nums[0] = nums[1];
            nums[1] = temp;
            return nums;
        }

        vector<int> ans(size,1);
        vector<int> left_product(size,1);
        vector<int> right_product(size,1);

        left_product[0] = nums[0];
        for(int i=1; i<size; i++){
            left_product[i] = left_product[i-1] * nums[i];
        }

        right_product[size-1] = nums[size-1];
        for(int j=size-2; j>=0; j--){
            right_product[j] = right_product[j+1] * nums[j];
        }
        
        if(size >= 3){
            ans[0] = right_product[1];
            ans[size-1] = left_product[size-2];
            for(int i=1; i<size-1; i++){
                ans[i] = left_product[i-1] * right_product[i+1];
            }
        }
        return ans;
    }
};