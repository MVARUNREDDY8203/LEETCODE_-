class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> ump(27, 0);
        for (int i=0; i<s.size(); i++) ump[s[i] - 'a']++;
        for (int i=0; i<s.size(); i++) if (ump[s[i] - 'a'] == 1) return i;
        return -1;
    }
};