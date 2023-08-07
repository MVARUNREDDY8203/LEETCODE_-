class Solution:
    def maxProfit(self, nums: List[int]) -> int:
        if reversed(nums) ==  nums : return 0
        prev_low = 0
        max_profit = 0
        for i in range(0,len(nums)):
            if(nums[i]<nums[prev_low]):
                prev_low = i
            max_profit = max(max_profit, nums[i]-nums[prev_low])
        return max_profit