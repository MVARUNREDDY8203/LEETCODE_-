class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        cvt = [int(time[:2]) * 60 + int(time[3:]) for time in timePoints]
        
        cvt.sort()
        ans = min(cvt[i] - cvt[i-1] for i in range(1, len(cvt)))
        
        ans = min(ans,1440 - (cvt[-1] - cvt[0]))
        return ans