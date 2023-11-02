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





// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         vector<vector<string>> ans;
//         unordered_map<int, vector<string>> ump;
//         for (int i=0; i<strs.size(); i++) {
//             long long int hv = 0;
//             for (int j=0; j<strs[i].size(); j++) {
//                 hv += strs[i][j] * strs[i][j] * strs[i][j] * strs[i][j];
//             }
//             ump[hv].push_back(strs[i]);
//         }
//         for (auto it: ump) ans.push_back(it.second);
//         return ans;
//     }
// };


// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& strs) {
//         unordered_map<string, vector<string>> mp;
//         for (auto i: strs) {
//             string s = i;
//             sort(s.begin(), s.end());
//             mp[s].push_back(i);
//         }
//         vector<vector<string>> ans;
//         for (auto it: mp) ans.push_back(it.second);
//         return ans;
//     }
// };




// class Solution {
// public:
//     vector<vector<string>> groupAnagrams(vector<string>& s) {
//         unordered_map<string, vector<string>> mp;

//         for(int i=0; i<s.size(); i++){
//             string temp = s[i];
//             sort(temp.begin(), temp.end());

//             mp[temp].push_back(s[i]);           
//         }
//         vector<vector<string>> ans;

//         for(auto i: mp){
//             ans.push_back(i.second);
//         }

        
//         return ans;
//         // unordered_map< unordered_map<char, int>, vector<string>> mp;
        
//         // for(int j=0; j<s.length(); j++){
//         //     string str = s[j];
//         //     unoredered_map<char, int> temp;
//         //     for(int i=0; i<str.length(); i++){
//         //         temp[str[i]]++;
//         //     }
            
//         //     for(int k=0; k<mp.size(); k++){
//         //         mp[temp].push_back(str);
//         //     }	
//         // }
//         // vector<vector<string>> ans;
//         // for(auto i: mp){
//         //     ans.push_back(i.second);
//         // }
//         // return ans;
//     }
// };