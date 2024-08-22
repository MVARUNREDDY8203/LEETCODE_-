class Solution:
    def findComplement(self, num: int) -> int:
        mask = ~0
        while mask & num:
            mask = mask << 1
        return ~num ^ mask