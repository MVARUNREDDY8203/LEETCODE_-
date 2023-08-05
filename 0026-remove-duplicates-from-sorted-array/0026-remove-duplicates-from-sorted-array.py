class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        k=1
        i=0
        while i in range (0,len(nums)-1):
            j=i+1
            if nums[j] == nums[i]:
                nums.remove(nums[j])
                continue
            i+=1
            k+=1
        return k