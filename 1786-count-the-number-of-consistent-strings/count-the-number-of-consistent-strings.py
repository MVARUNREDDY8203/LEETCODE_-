class Solution:
    def countConsistentStrings(self, allowed: str, words: List[str]) -> int:
        freq = [0] * 26
        for char in allowed:
            freq[ord(char) - ord('a')] += 1
        cnt = 0
        for word in words:
            flag = True
            for char in word:
                if freq[ord(char) - ord('a')] == 0:
                    flag = False
                    break
            if flag:
                cnt+=1
            
        return cnt