class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> ump1;
        for (auto i: t) ump1[i]++;

        int start = 0, end = 0, cnt = 0, ans_l, ans_r, size = INT_MAX;
        unordered_map<int, int> ump2;
        while (end < s.size()) {
            ump2[s[end]]++;
            if (ump2[s[end]] <= ump1[s[end]]) cnt++; // means a necessity char is found and so cnt is increased

            while (cnt >= t.size()) {   // while minimum necessity condition is true
                if (end - start + 1 < size) {
                    size = end - start + 1;
                    ans_l = start;
                    ans_r = end;
                }
                ump2[s[start]]--;
                if (ump2[s[start]] < ump1[s[start]]) {
                    cnt--;
                }
                start++;
            }
            end++;
        }
        
        return size == INT_MAX ? "" : s.substr(ans_l, ans_r-ans_l+1);

    }
};

// class Solution {
// public:
//     string minWindow(string s, string t) {
//         unordered_map<int, int> ump_dict;
//         for (auto i: t) ump_dict[i]++;

//         int l = -1, r = -1, ans = INT_MAX;
//         for (int i=0; i<s.size(); i++) {
//             if (ump_dict.find(s[i]) == ump_dict.end()) continue;
//             unordered_map<int, int> ump_curr = ump_dict;
//             for (int j=i; j<s.size(); j++) {
//                 if (ump_curr.find(s[j]) != ump_curr.end()) {
//                     ump_curr[s[j]]--;
//                     if (ump_curr[s[j]] <= 0) ump_curr.erase(s[j]);
//                 }
//                 if (ump_curr.size() == 0) {
//                     if (j-i+1 < ans) {
//                         ans = j-i+1;
//                         r = j;
//                         l = i;
//                     }
//                 }
//             }
//         }
//         return ans == INT_MAX ? "" : s.substr(l, r-l+1);
//     }
// };