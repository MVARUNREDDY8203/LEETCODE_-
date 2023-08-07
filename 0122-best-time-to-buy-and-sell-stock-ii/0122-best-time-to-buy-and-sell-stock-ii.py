class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        max_profit = 0
        prev_min = 0
        if len(prices) <= 1 : return 0

        for i in range(1,len(prices)):
            # if prices[i] <= prices[i-1] or prices[i] :
            #     prev_min = i
            max_profit = max(max_profit, max_profit+(prices[i]-prices[i-1]))
        return max_profit