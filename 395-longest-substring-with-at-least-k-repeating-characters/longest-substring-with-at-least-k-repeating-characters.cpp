class Solution {
public:
    int util(string s, int k) {
        if (s.size() < k) return 0;
        
        unordered_map<int, int> count;
        for (auto i: s) count[i]++;

        for (auto it: count) {
            if (it.second < k) {
                for (int i=0; i<s.size(); i++) {
                    if (s[i] == it.first) {
                        int l_ans = util(s.substr(0, i), k);
                        int r_ans = util(s.substr(i+1, s.size() - (i+1)), k);
                        return max(l_ans, r_ans);
                    }
                }
            }
        }
        return s.size();
    }
    int longestSubstring(string s, int k) {
        return util(s, k);
    }
};