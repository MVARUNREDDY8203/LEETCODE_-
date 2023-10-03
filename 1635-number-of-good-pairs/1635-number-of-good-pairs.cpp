class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> ump;
        int count = 0;
        for (auto i: nums) {
            if (ump.find(i) != ump.end()) count += ump[i];
            ump[i]++;
        }
        return count;
    }
};