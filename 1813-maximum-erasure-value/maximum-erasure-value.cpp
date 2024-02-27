class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int start = 0, end = 0, ans = 0, sum = 0;
        unordered_set<int> dict;
        while (end < nums.size()) {
            // cout<<start<<" "<<end<<endl;
            if (dict.count(nums[end])) {
                while (dict.count(nums[end])) {
                    sum -= nums[start];
                    dict.erase(nums[start++]);
                }
            }
            else {
                sum += nums[end];
                dict.insert(nums[end++]);
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};