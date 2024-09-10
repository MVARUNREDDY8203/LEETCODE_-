class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        m = len(points)
        n = len(points[0])

        prev_row = points[0]

        for row in range(1, m):
            left_max = [0] * n
            right_max = [0] * n
            curr_row = [0] * n

            left_max[0] = prev_row[0]
            for col in range(1, n):
                left_max[col] = max(left_max[col-1] - 1, prev_row[col])
            
            right_max[-1] = prev_row[-1]
            for col in range(n-2, -1, -1):
                right_max[col] = max(right_max[col+1] - 1, prev_row[col]) 
            
            for col in range(0, n):
                curr_row[col] = points[row][col] + max(left_max[col], right_max[col])
            
            prev_row = curr_row
        
        return max(prev_row)