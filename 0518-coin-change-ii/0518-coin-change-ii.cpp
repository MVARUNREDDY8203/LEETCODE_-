// class Solution {
// public:
//     int noOfWays(int amount, int rem_amt, vector<int>& coins, vector<int> &dp){
//         if(dp[rem_amt] != -1) return dp[rem_amt];
//         if(rem_amt == 0) return 0;

//         for(int i=0; i<coins.size(); i++){
//             rem_amt = 
//         }
//     }
//     int change(int amount, vector<int>& coins) {
//         vector<int> dp(-1,amount);
//         return noOfWays(amount, coins, dp);
//     }
// };
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        
        for (int coin : coins) {
            for (int j = coin; j <= amount; j++) {
                dp[j] += dp[j - coin];
            }
        }
        
        return dp[amount];
    }
};