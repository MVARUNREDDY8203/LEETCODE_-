class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        temp = ""
        ans = ""
        for i in s:
            if i != " ":
                temp += i
            elif len(temp) > 0:
                ans = temp
                temp = ""
        if len(temp) > 0:
            ans = temp
        return len(ans)