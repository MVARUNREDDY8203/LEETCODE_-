class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> ump;
        for (auto i: nums) ump[i]++;

        for (auto i: ump) {
            if (i.second > n/2) return i.first;
        }
        return -1;
    }
};