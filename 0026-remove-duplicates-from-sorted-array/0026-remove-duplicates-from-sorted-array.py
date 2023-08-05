# class Solution:
#     def removeDuplicates(self, nums: List[int]) -> int:
#         k=1
#         i=0
#         while i in range (0,len(nums)-1):
#             j=i+1
#             if nums[j] == nums[i]:
#                 nums.remove(nums[j])
#                 continue
#             i+=1
#             k+=1
#         return k

class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        left , right = 0,1
        k=1
        if len(nums) == 1: return 1
        while right <= len(nums)-1:
            if nums[right] > nums[left]:
                nums[left+1] = nums[right]
                left += 1
                k+=1
            right+=1
        return k