class Solution:
    def generate(self, n: int) -> List[List[int]]:
        ans = []
        ans.append([1])
        if n == 1:
            return ans
        ans.append([1,1])
        for i in range(2, n):
            temp = [1]
            curr_size = len(ans[-1])+1
            for j in range(1, curr_size-1):
                temp.append(ans[i-1][j-1] + ans[i-1][j])
            temp.append(1)
            ans.append(temp)
        return ans