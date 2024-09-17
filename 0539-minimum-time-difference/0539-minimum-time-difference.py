class Solution:
    def findMinDifference(self, timePoints: List[str]) -> int:
        cvt = []
        for time in timePoints:
            hrs = int(time[0]) * 10 + int(time[1])
            mins = hrs * 60 + int(time[3]) * 10 + int(time[4])
            cvt.append(mins)
        
        cvt.sort()
        ans = float('inf')
        for i in range(1, len(timePoints)):
            ans = min(ans, cvt[i] - cvt[i-1])
        
        ans = min(ans,1440 - (cvt[-1] - cvt[0]))
        return ans
        
        return ans