class Solution:
    def xorQueries(self, arr: List[int], queries: List[List[int]]) -> List[int]:
        prefix_xor = [0] * (len(arr) + 1)
        for i in range(1, len(arr)+1):
            prefix_xor[i] = arr[i-1] ^ prefix_xor[i-1]
        
        ans = [prefix_xor[r+1] ^ prefix_xor[l] for l,r in queries]
        return ans