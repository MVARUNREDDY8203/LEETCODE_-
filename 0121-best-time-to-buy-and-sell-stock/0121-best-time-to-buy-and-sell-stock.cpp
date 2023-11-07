class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0, buy=prices[0], sell, size = prices.size();
        for(int i=0; i<size; i++){
            buy = min(buy, prices[i]);
            profit = max(profit, prices[i] - buy);
        }
        return profit;
    }
};