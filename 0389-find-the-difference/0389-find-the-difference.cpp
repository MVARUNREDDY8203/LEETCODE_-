class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> ump1, ump2;
        for (auto i: s) ump1[i]++;
        for (auto i: t) ump2[i]++;
        for (auto i: t) {
            if (ump1.find(i) == ump1.end()) return i;
            if (ump1[i] != ump2[i]) return i;
        }
        return t[0];
    }
};