class Solution {
public:
    unordered_set<string> uset;
    int ans = -1;
    void util(int i, int cnt, string curr, string &s) {
        int n = s.size();
        if (i >= s.size()) {
            ans = max(ans, cnt);
            return;
        }

        for (int j=i; j<n; j++) {
            curr += s[j];
            if (!uset.count(curr)) {
                uset.insert(curr);
                util(j+1, cnt+1, "", s);
                uset.erase(curr);
            }
        }
    }
    int maxUniqueSplit(string s) {
        int n = s.size();
        util(0, 0, "", s);
        return ans;
        
    }
};