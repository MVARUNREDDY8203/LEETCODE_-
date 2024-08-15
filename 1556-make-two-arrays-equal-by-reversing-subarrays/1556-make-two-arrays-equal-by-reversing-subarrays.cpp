class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int, int> ump;
        for (auto i: target) ump[i]++;
        for (auto j: arr) ump[j]--;
        for (auto i: ump) if (i.second != 0) return false; 
        return true;
    }
};