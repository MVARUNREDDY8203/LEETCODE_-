class Solution {
public:
    long long int coinChangeUtil(vector<int>&coins, int amt, vector<int> &dp) {
        if(amt == 0) return 0;
        if(amt < 0) return INT_MAX;
        if(dp[amt] != -1) return dp[amt];

        long long int min_nos = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            long long int temp =  coinChangeUtil(coins, amt-coins[i], dp);
            min_nos = min(min_nos, 1 + temp);
        }
        dp[amt] = min_nos;
        return min_nos;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans = coinChangeUtil(coins, amount, dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};