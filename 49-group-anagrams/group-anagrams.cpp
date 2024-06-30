class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> mp;
        int n = strs.size();
        for (int i=0; i<n; i++) {
            map<char, int> ump;
            for (auto c: strs[i]) ump[c]++;
            mp[ump].push_back(strs[i]);
        }
        vector<vector<string>> ans;

        for (auto it: mp) ans.push_back(it.second);
        return  ans;
    }
};