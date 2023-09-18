class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        vector<int> binary(nums.size()+1, 0);
        binary[0] = 0;
        binary[1] = 1;
        for(int i=2; i<=nums.size(); i++){
            binary[i] = binary[i/2] + i%2;
        }
        
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(binary[i] == k) count+=nums[i];
        }
        return count;
    }
};