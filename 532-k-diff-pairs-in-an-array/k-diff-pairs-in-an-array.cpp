class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int, int> ump;
        for (auto i: nums) ump[i]++;
        if (k==0) {
            for (auto i: ump) {
                if (i.second > 1) ans ++;
            }
        } 
        else {
            unordered_map<int, pair<int, int>> ump2;
            for (int i=0; i<nums.size(); i++) {
                int lesser = nums[i] - k;
                int greater = nums[i] + k;
                if (ump.count(lesser)) {
                    if (ump2[lesser].second != nums[i]) {
                        ump2[lesser].second = nums[i];
                        ump2[nums[i]].first = lesser;
                        ans++;
                    }
                }
                if (ump.count(greater)) {
                    if (ump2[greater].first != nums[i]) {
                        ump2[greater].first = nums[i];
                        ump2[nums[i]].second = greater;
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};