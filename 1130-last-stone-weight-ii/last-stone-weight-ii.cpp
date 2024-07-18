class Solution {
public:
    int sum = 0;
    // unordered_map<pair<int, int>, int> dp;
    int dp[31][3001];
    int util(int i, int curr_sum, int total, vector<int> &stones) {
        if (i >= stones.size() || curr_sum >= total) return abs(curr_sum - (sum - curr_sum));

        if (dp[i][curr_sum] != -1) return dp[i][curr_sum];

        int not_take = util(i+1, curr_sum, total, stones);
        int take = util(i+1, curr_sum + stones[i], total, stones);

        return dp[i][curr_sum] = min(take, not_take);
    }
    int lastStoneWeightII(vector<int>& stones) {
        for (auto i: stones) sum += i;
        memset(dp, -1, sizeof(dp));
        return util(0, 0, sum/2, stones);
    }
};