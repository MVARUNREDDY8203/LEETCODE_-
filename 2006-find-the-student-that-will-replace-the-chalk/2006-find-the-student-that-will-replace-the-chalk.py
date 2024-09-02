class Solution:
    def chalkReplacer(self, chalk: List[int], k: int) -> int:
        total_sum = sum(chalk)
        
        k = k % total_sum
        for i in range(0, len(chalk)):
            if k < chalk[i]:
                return i
            k -= chalk[i]
        
        return -1