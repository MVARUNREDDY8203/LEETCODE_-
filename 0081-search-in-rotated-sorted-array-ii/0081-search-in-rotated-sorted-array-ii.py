class Solution:
    def search(self, nums: List[int], target: int) -> bool:
        for x in nums:
            if x == target:
                return True

        return False