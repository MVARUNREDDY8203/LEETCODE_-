class Solution {
public:
    int countPalindromicSubsequence(string s) {
        vector<int> first(26, INT_MAX), last(26, INT_MIN);
        int n = s.size();
        for (int i=0; i<n; i++) {
            first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
            last[s[i] - 'a'] = max(last[s[i] - 'a'], i);
        }
        
        int ans = 0;
        for (int i=0; i<26; i++) {
            vector<int> freq(26, 0);
            if (first[i] < last[i]) {
                for (int j=first[i]+1; j<last[i]; j++) {
                    freq[s[j] - 'a']++;
                }
                int cnt = 0;
                for (auto i: freq) if (i > 0) cnt++;
                ans += cnt;
            }
        }
        return ans;
    }
};


// class Solution {
// public:
//     int countPalindromicSubsequence(string s) {
//         vector<int> first(26, INT_MAX), last(26, INT_MIN);
//         int n = s.size();
//         for (int i=0; i<n; i++) {
//             first[s[i] - 'a'] = min(first[s[i] - 'a'], i);
//             last[s[i] - 'a'] = max(last[s[i] - 'a'], i);
//         }
        
//         int ans = 0;
//         for (int i=0; i<26; i++) {
//             if (first[i] < last[i]) {
//                 ans += unordered_set<int>(s.begin() + first[i] + 1, s.begin()+last[i]).size();
//             }
//         }
//         return ans;
//     }
// };


// class Solution {
// public:
//     int countPalindromicSubsequence(string s) {
//         vector<int> last_occ_of(26, -1);
//         int n = s.size();
//         for (int i=0; i<n; i++) last_occ_of[s[i] - 'a'] = i;

//         int i = 0, ans = 0;
//         unordered_map<string, int> ump;
//         while (i < n) {
//             if (i < last_occ_of[s[i]-'a']-1) {
//                 for (int j=i+1; j<last_occ_of[s[i]-'a']; j++) {
//                     string t = "";
//                     t += s[i];
//                     t += s[j];
//                     t += s[i];
//                     ump[t]++;
//                 }
//             }
//             i++;
//         }
//         return ump.size();
//     }
// };



// class Solution {
// public:
//     int countPalindromicSubsequence(string s) {
//         vector<int> last_occ_of(26, -1);
//         int n = s.size();
//         for (int i=0; i<n; i++) last_occ_of[s[i] - 'a'] = i;

//         int i = 0, ans = 0;
//         unordered_map<string, int> ump;
//         while (i < n) {
//             if (i < last_occ_of[s[i]-'a']-1) {
//                 for (int j=i+1; j<last_occ_of[s[i]-'a']; j++) {
//                     string t = "";
//                     t += s[i];
//                     t += s[j];
//                     t += s[i];
//                     ump[t]++;
//                 }
//             }
//             i++;
//         }
//         return ump.size();
//     }
// };