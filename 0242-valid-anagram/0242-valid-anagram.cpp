class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<int, int> ump;
        for (int i=0; i<s.size(); i++) ump[s[i]]++;
        for (int i=0; i<t.size(); i++) {
            if (ump.find(t[i]) == ump.end()) return false;
            ump[t[i]]--;
        }
        for (auto it : ump) if (it.second > 0) return false;
        return true;
    }
};

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         sort(s.begin(), s.end());
//         sort(t.begin(), t.end());
//         return s==t;
//     }
// };

// class Solution {
// public:
//     bool isAnagram(string s, string t) {
//         int ssize = s.size();
//         int tsize = t.size();

//         if(ssize != tsize){
//             return false;
//         }

//         map<char,int> mp;
//         for(int i=0; i<ssize; i++){
//             mp[s[i]]++;
//         }

//         for(int i=0; i<tsize; i++){
//             mp[t[i]]--;
//         }

//         for(auto &it: mp){
//             if((it).second > 0){
//                 return false;
//             }
//         }

//         return true;
//     }
// };