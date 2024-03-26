class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // unordered_map<int, int> ump;
        int ump[256] = {0};
        int start = 0, e = 0, n = s.size(), ans = 0;
        while (e < n) {
            ump[s[e]]++;
            while (ump[s[e]] > 1) {
                ump[s[start++]]--;
            }
            ans = max(ans, e - start +1);
            e++;
        }
        return ans;
    }
};









// class Solution {
// public:
//     int lengthOfLongestSubstring(string s) {
//         vector<int> dict(256, -1);
//         int start = -1, maxLen =0;
//         for(int i=0; i<s.length(); i++){
//             if(dict[s[i]] > start){
//                 start = dict[s[i]];
//             }

//             dict[s[i]] = i;
//             maxLen = max(maxLen, i-start);
//         }
//         return maxLen;
//     }
// };