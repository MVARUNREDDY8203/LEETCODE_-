class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for (int i=0; i<words.size(); i++) {
            int j = 0;
            while (j < pref.size() && j < words[i].size()) {
                if (words[i][j] == pref[j]) j++;
                else break;
            }
            if (j == pref.size()) ans++;
        }
        return ans;
    }
};