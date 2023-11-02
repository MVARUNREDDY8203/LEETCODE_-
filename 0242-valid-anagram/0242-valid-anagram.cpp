class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s==t;
    }
};

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