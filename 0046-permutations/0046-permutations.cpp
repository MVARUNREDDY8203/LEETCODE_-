class Solution {
public:
    vector<vector<int>> ans;
    void ap_util(vector<int> &nums, int i, int n) {
        if (i == n) {
            ans.push_back(nums);
            return;
        }
        for (int j=i; j<=n; j++) {
            swap(nums[j], nums[i]);
            ap_util(nums, i+1, n);
            swap(nums[j], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        ap_util(nums, 0, nums.size()-1);
        return ans;
    }
};
    // SOLUTION 2 - BEGGING ONE , PROBABLY > N! SPACE & TIME COMPLEXITY
    // vector<vector<int>> all_permutations;
    // vector<unordered_set<int>> ap_ust;
    // void ap_util(vector<int> &nums, vector<int> curr, unordered_set<int> ust){
    //     for (auto i: curr) {
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    //     if (curr.size() == nums.size()) {
    //         all_permutations.push_back(curr);
    //         return;
    //     }
    //     for (auto i: nums) {
    //         if (ust.find(i) != ust.end()) continue;
    //         vector<int> temp = curr;
    //         temp.push_back(i);
    //         unordered_set<int> temp_ust = ust;
    //         temp_ust.insert(i);
    //         ap_util(nums, temp, temp_ust);
    //     }
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     for (auto i: nums) {
    //         vector<int> temp;
    //         unordered_set<int> ust;
    //         temp.push_back(i);
    //         ust.insert(i);
    //         ap_util(nums, temp, ust);
    //     }
    //     return all_permutations;
    // }

    // SOLUTION 1 - GENERATING THE NEXT PERMUTATION FOR GIVEN NUMS 
    // vector<int> next_permutation_of(vector<int> nums) {
    //     int i=nums.size()-1;
    //     for (i=i; i>0; i--) {
    //         if (nums[i] > nums[i-1]) break;
    //     }
    //     i--;
    //     if (i < 0) {
    //         reverse(nums.begin(), nums.end());
    //     }
    //     else {
    //         for (int j=nums.size()-1; j>i; j--) {
    //             if (nums[j] > nums[i]) {
    //                 swap(nums[j], nums[i]);
    //                 reverse(nums.begin()+i+1, nums.end());
    //                 break;
    //             }
    //         }
    //     }
    //     return nums;
    // }
    // int factorial (int n) {
    //     if (n <= 0) return 1;
    //     return n * factorial(n-1);
    // }
    // vector<vector<int>> permute(vector<int>& nums) {
    //     int total_permutations = factorial(nums.size());
    //     vector<vector<int>> ans;
    //     vector<int> temp;
    //     ans.push_back(nums);

    //     if(nums.size() == 1) return ans;

    //     while (total_permutations-1 > 0) {
    //         ans.push_back(next_permutation_of(ans.back()));

    //         total_permutations--;
    //     }
    //     return ans;
    // }