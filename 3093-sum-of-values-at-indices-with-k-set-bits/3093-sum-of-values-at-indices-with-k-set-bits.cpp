class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        vector<int> binary(100001, 0);
        binary[0] = 0;
        binary[1] = 1;
        for(int i=2; i<=100000; i++){
            binary[i] = binary[i/2] + i%2;
        }
        
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            cout<<nums[i]<<" "<<binary[nums[i]]<<" ";
            if(binary[i] == k) count+=nums[i];
        }
        cout<<endl;
        return count;
    }
};