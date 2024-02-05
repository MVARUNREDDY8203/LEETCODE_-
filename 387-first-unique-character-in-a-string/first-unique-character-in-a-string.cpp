class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> ump;
        for (auto i: s) ump[i]++;
        char t = '0';
        for (int i=0; i<s.size(); i++) if (ump[s[i]] == 1) return i;
        return -1;
    }
};