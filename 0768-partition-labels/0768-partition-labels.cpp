class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> ump_last;
        int n = s.size();
        for (int i=0; i<n; i++) {
            if (ump_last.find(s[i]) == ump_last.end()) ump_last[s[i]] = i;
            else ump_last[s[i]] = max(i, ump_last[s[i]]);
        }
        vector<int> ans;
        int end = -1, len = 0, ptr = 0;
        while (ptr < n) {
            if (ump_last[s[ptr]] >= end) end = ump_last[s[ptr]];
            if (ptr == end) {
                ans.emplace_back(++len);
                len = 0;
                ptr++;
                continue;
            }
            len++;
            ptr++;
        }
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> partitionLabels(string s) {
//         int n = s.size(), ptr = 0, len = 0, end = -1, r = 0;
//         vector<int> ans;
//         unordered_set<char> ust;
//         while (ptr < n) {
//             if (ust.find(s[ptr]) != ust.end()) {
//                 ptr++;
//                 len++;
//                 continue;
//             }
//             if (ptr == end) {
//                 ans.emplace_back(++len);
//                 len = 0;
//                 ptr++;
//             }
//             r = n-1;
//             while (r >= ptr) {
//                 if (s[r] == s[ptr]) break;
//                 r--;
//             }
//             if (r > end) end = r;
//             if (ptr == end) {
//                 ans.emplace_back(++len);
//                 len = 0;
//                 ptr++;
//                 continue;
//             }
//             ptr++;
//             len++;                        
//         }
//         return ans;
//     }
// };