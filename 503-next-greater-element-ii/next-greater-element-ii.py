class Solution:
    def nextGreaterElements(self, nums: List[int]) -> List[int]:
        n = len(nums)
        lim = 1000000001
        ans = [lim] * n
        mono = []
        for i in range(2*n-1, -1, -1):
            if (ans[(i%n)] != lim):
                continue

            while (len(mono) >= 1 and mono[-1] <= nums[(i%n)]):
                mono.pop()
            if (len(mono) >= 1):
                ans[(i%n)] = mono[-1]

            mono.append(nums[(i%n)])
        
        ans = [-1 if i == lim else i for i in ans]
        return ans