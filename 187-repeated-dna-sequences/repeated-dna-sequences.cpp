class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        if (s.size() <= 10) return {};
        unordered_map<string, int> dict;
        for (int i=0; i<=s.size()-10; i++) dict[s.substr(i, 10)]++;
        vector<string> ans;
        for (auto i: dict) if (i.second >= 2) ans.push_back(i.first);
        return ans;
    }
};

// class Solution {
// public:
//     vector<string> findRepeatedDnaSequences(string s) {
//         if (s.size() <= 10) return {};
//         unordered_set<string> ans;
//         unordered_set<string> dict;
//         for (int i=0; i<=s.size()-10; i++) {
//             string subs = s.substr(i, 10);
//             if (dict.count(subs)) ans.insert(subs);
//             else dict.insert(subs);
//             cout<<i<<endl;
//         }
//         vector<string> vans;
//         for (auto i: dict) cout<<i<<" ";
//         for (auto i: ans) vans.push_back(i);
//         return vans;
//     }
// };