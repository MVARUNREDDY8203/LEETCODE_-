class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        ones = True
        for i in range(len(nums)):
            if(nums[i] == 0):
                ones = False
                break
        if(ones): return len(nums)-1
        prev = curr = max_len = 0;
        for i in range(len(nums)):
            if(nums[i] == 0):
                max_len = max(max_len, prev+curr)
                prev = curr
                curr = 0
            else:
                curr+=1
        return max(max_len, prev+curr)
