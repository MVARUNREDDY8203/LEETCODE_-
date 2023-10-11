class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int pc1 = 0, pc2 = 0, cnt1 = 0, cnt2 = 0;

        for (int i=0; i<n; i++) {
            if (nums[i] == pc1) cnt1++;
            else if (nums[i] == pc2) cnt2++;

            else if (cnt1 == 0 && nums[i] != pc2) {
                pc1 = nums[i];
                cnt1 = 1;
            }
            else if (cnt2 == 0 && nums[i] != pc1) {
                pc2 = nums[i];
                cnt2 = 1;
            }
            else {
                cnt1--;
                cnt2--;
            }
        }

        // cout<<pc1<<" "<<pc2;
        cnt1 = 0;
        cnt2 = 0;
        for (int i=0; i<n; i++) {
            if (nums[i] == pc1) cnt1++;
            else if (nums[i] == pc2) cnt2++;
        }
        // cout<<endl<<cnt1<<" "<<cnt2;
        if (cnt1 > n/3) {
            if (cnt2 > n/3) return {pc1, pc2};
            else return {pc1};
        }
        if (cnt2 > n/3) return {pc2};
        return {};
    }
};

// -------------------- O(nlogn) time, O(1) space -----------------------
// class Solution {
// public:
//     vector<int> majorityElement(vector<int>& nums) {
//         vector<int> ans;
//         sort(nums.begin(), nums.end());
//         int n = nums.size();
//         int n_by_3 = n/3;
//         int prev = 1e9+1;

//         for (int i=0, j = n_by_3; i< n - n_by_3; i++, j++) {
//             if (nums[i] != prev && nums[i] == nums[j]) {
//                 ans.emplace_back(nums[i]);
//                 i = j;
//                 j += n_by_3;
//                 prev = nums[i];
//             }
//         }
//         return ans;
//     }
// };
//
// ----------===----- O(n) time, O(n) space ---------------------------------
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