class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        mono_stk = []
        n = len(num)
        m = 0
        for char in num:
            while mono_stk and mono_stk[-1] > char and m < k:
                mono_stk.pop()
                m += 1
            mono_stk.append(char)
        
        while m < k:
            mono_stk.pop()
            m += 1
            
        result = ''.join(mono_stk).lstrip('0')
        
        return result if result else '0'
        
        