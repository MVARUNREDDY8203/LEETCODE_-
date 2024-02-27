class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        vector<int> dict(10001, 0);
        int start = 0, end = 0, ans = 0, sum = 0;
        while (end < nums.size()) {
            while (dict[nums[end]] > 0) {
                sum -= nums[start];
                dict[nums[start++]]--;
            }
            sum += nums[end];
            dict[nums[end++]]++;
            ans = max(ans, sum);
        }
        return ans;
    }
};


// class Solution {
// public:
//     int maximumUniqueSubarray(vector<int>& nums) {
//         int start = 0, end = 0, ans = 0, sum = 0;
//         unordered_set<int> dict;
//         while (end < nums.size()) {
//             if (dict.count(nums[end])) {
//                 while (dict.count(nums[end])) {
//                     sum -= nums[start];
//                     dict.erase(nums[start++]);
//                 }
//             }
//             else {
//                 sum += nums[end];
//                 dict.insert(nums[end++]);
//             }
//             ans = max(ans, sum);
//         }
//         return ans;
//     }
// };