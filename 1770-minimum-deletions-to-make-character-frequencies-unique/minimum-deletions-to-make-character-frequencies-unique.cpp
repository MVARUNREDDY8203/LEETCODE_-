class Solution {
public:
    int util(int i, vector<int> &freq, int prev) {
        if (i < 0) return 0;
        if (freq[i] == 0) return 0;
        if (freq[i] == prev) {
            return 1 + util(i-1, freq, --freq[i]);
        }
        return util(i-1, freq, freq[i]);
    }
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for (auto i: s) freq[i - 'a']++;
        sort(freq.begin(), freq.end());
        int ans = 0;
        for (int i=0; i<=25; i++) {
            ans += util(i, freq, -1);
        }
        return ans;
    }
};