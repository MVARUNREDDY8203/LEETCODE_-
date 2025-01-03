class Solution {
public:
    int freq[26][1000];
    string tar;
    int words_size;
    int mod = 1000000007;

    int dp[1000][1000];
    int util(int i, int j) {
        if (i >= tar.size()) return 1;
        if (j >= words_size) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = ((long long)util(i, j+1) + (long long)freq[tar[i] - 'a'][j] * (long long)util(i+1, j+1)) % mod;
    }
    int numWays(vector<string>& words, string target) {
        memset(freq, 0, sizeof(freq));
        for (int i=0; i<words.size(); i++) {
            for (int j=0; j<words[i].size(); j++) {
                freq[words[i][j] - 'a'][j]++;
            }
        }
        words_size = words[0].size();
        tar = target;

        memset(dp, -1, sizeof(dp));

        return util(0, 0);

    }
};