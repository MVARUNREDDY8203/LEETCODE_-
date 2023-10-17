class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> ump;
        for (auto i: nums) {
            ump[i]++;
        }
        
        vector<pair<int, int>> temp;

        for (auto it = ump.begin(); it != ump.end(); it++) {
            temp.push_back({it->first, it->second});
        }
        sort (temp.begin(), temp.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        vector<int> ans;
        for (auto i: temp) {
            if (k <= 0) break;
            ans.push_back(i.first);
            k--;
        }
        return ans;
    }
};