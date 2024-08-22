class Solution:
    def numberOfAlternatingGroups(self, colors: List[int]) -> int:
        colors.append(colors[0])
        colors.append(colors[1])

        cnt = 0
        for i in range(1, len(colors)-1):
            if colors[i] != colors[i-1] and colors[i-1] == colors[i+1]:
                cnt += 1
        return cnt