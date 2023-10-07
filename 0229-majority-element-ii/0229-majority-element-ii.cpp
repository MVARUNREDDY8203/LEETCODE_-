class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int n_by_3 = n/3;
        int prev = 1e9+1;

        for (int i=0, j = n_by_3; i< n - n_by_3; i++, j++) {
            if (nums[i] != prev && nums[i] == nums[j]) {
                ans.emplace_back(nums[i]);
                i = j;
                j += n_by_3;
                prev = nums[i];
            }
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         int n = nums.size();
//         int n_by_3 = n/3;
//         unordered_map<int, int> ump;
//         for (auto i: nums) ump[i]++;
//         vector<int> ans;
//         for (auto i: ump) {
//             if (i.second > n_by_3) ans.emplace_back(i.first);
//         }
//         return ans;
//     }
// };