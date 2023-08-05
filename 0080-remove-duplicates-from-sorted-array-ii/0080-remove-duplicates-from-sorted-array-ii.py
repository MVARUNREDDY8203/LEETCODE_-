class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        count = 0
        k = 1
        right = 0
        left = 0
        while right < len(nums):
            if nums[right] == nums[left] and count < 2:
                count+=1
                right+=1
                k+=1
            elif nums[right] == nums[left] and count >= 2:
                nums.pop(right)
            else:
                count=1
                left=right
                right+=1
                k+=1
        return k