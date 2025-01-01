class Solution {
public:
    int maxScore(string s) {
        int zeros = 0, ones = 0, best = INT_MIN, n = s.size();
        for (int i=0; i<n-1; i++) {
            if (s[i] == '0') zeros++;
            else ones++;

            best = max(best, zeros - ones);
        }
        if (s[n-1] == '1') ones++;
        return best + ones;
    }
};