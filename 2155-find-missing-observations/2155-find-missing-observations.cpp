class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int m_sum = 0;
        for (auto i: rolls) m_sum += i;
        int n_sum = mean * (m + n) - m_sum;
        if ((double)((double)n_sum /(double) n) > 6.0 || (double)((double)n_sum /(double) n) < 1.0) return {};
        vector<int> ans(n, 0);
        int idx = 0;
        while (n_sum) {
            ans[idx] += 1;
            n_sum--;
            idx = (idx+1)%n;
        }
        return ans;
    }
};