class Solution:
    def maxDistance(self, arr: List[List[int]]) -> int:
        lv = arr[0][0]
        hv = arr[0][-1]
        ans = 0

        for i in range(1, len(arr)):
            ans = max(ans, hv - arr[i][0])
            ans = max(ans, arr[i][-1] - lv)
            hv = max(hv, arr[i][-1])
            lv = min(lv, arr[i][0])
        
        return ans