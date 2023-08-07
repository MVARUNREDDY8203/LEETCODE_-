class Solution:
    def canJump(self, nums: List[int]) -> bool:
        
        if len(nums) == 1 : return True
        for i in range(0,len(nums)):
            can_cross = False
            if nums[i] == 0 and not i == len(nums)-1:
                count = 1
                for x in reversed(nums[:i]):
                    if x > count:
                        can_cross = True
                        break
                    count+=1
                if not can_cross:
                    return False
        return True

                        