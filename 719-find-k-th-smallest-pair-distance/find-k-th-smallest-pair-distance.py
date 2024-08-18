class Solution:
    def smallestDistancePair(self, nums: List[int], k: int) -> int:
        def enough(nums: List[int], diff: int):
            count = i = j = 0
            while i < n or j < n:
                while j < n and nums[j] - nums[i] <= diff:
                    j += 1
                count += j - i - 1
                i += 1
            return count
        nums.sort()
        n = len(nums)
        l, r = 0, nums[-1] - nums[0]

        while l < r:
            mid = l + (r - l) // 2
            if enough(nums, mid) >= k:
                r = mid
            else:
                l = mid + 1
        
        return l