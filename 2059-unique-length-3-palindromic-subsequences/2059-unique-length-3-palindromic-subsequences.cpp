class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<int, pair<int, int>> fl;
        int n = s.size();
        for (int i=0; i<n; i++) {
            if (fl.count(s[i])) {
                fl[s[i]].first = min(fl[s[i]].first, i);
                fl[s[i]].second = max(fl[s[i]].second, i);
            }
            else fl[s[i]] = {i, i};
        }

        unordered_map<string, int> uset;
        for (int i=0; i<n; i++) {
            for (auto it: fl) {
                if (it.second.first < it.second.second && i > it.second.first  && i < it.second.second) {
                    string t = "";
                    t += (char)it.first;
                    t += s[i];
                    t += (char)it.first;
                    uset[t]++;
                } 
            }
        }

        return uset.size();
    }
};