class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size(), ptr = 0, len = 0, end = -1, r = 0;
        vector<int> ans;
        unordered_set<int> ust;
        while (ptr < n) {
            if (ust.find(s[ptr]) != ust.end()) {
                ptr++;
                len++;
                continue;
            }
            if (ptr == end) {
                ans.emplace_back(++len);
                len = 0;
                ptr++;
            }
            r = n-1;
            while (r >= ptr) {
                if (s[r] == s[ptr]) break;
                r--;
            }
            if (r > end) end = r;
            if (ptr == end) {
                ans.emplace_back(++len);
                len = 0;
                ptr++;
                continue;
            }
            ptr++;
            len++;                        
        }
        return ans;
    }
};