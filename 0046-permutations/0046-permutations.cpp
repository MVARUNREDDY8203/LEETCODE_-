class Solution {
public:
    vector<int> next_permutation_of(vector<int> nums) {
        int i=nums.size()-1;
        for (i=i; i>0; i--) {
            if (nums[i] > nums[i-1]) break;
        }
        i--;
        if (i < 0) {
            reverse(nums.begin(), nums.end());
        }
        else {
            for (int j=nums.size()-1; j>i; j--) {
                if (nums[j] > nums[i]) {
                    swap(nums[j], nums[i]);
                    reverse(nums.begin()+i+1, nums.end());
                    break;
                }
            }
        }
        return nums;
    }
    int factorial (int n) {
        if (n <= 0) return 1;
        return n * factorial(n-1);
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int total_permutations = factorial(nums.size());
        vector<vector<int>> ans;
        vector<int> temp;
        ans.push_back(nums);

        if(nums.size() == 1) return ans;

        while (total_permutations-1 > 0) {
            ans.push_back(next_permutation_of(ans.back()));

            total_permutations--;
        }
        return ans;
    }
};