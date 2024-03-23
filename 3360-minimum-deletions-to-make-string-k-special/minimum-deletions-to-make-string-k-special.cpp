class Solution {
public:
    int util (int i, int j, int freq[], string word, int k, vector<vector<int>> &dp) {
        if (i >= j) return 0;
        if (freq[i] == 0) return dp[i][j] = util (i+1, j, freq, word, k, dp);
        if (freq[j] - freq[i] <= k) return 0;

        if (dp[i][j] != -1) return dp[i][j];
        int left_deletions = freq[i] + util(i+1, j, freq, word, k, dp);
        int right_deletions = (freq[j] - freq[i]) - k + util(i, j-1, freq, word, k, dp);

        return dp[i][j] = min(left_deletions, right_deletions);
    }
    int minimumDeletions(string word, int k) {
        int freq[26] = {0};
        vector<vector<int>> dp(26, vector<int>(26, -1));
        for (auto i : word) freq[i - 'a']++;

        sort(freq, freq+26);

        return util(0, 25, freq, word, k, dp);
    }
};