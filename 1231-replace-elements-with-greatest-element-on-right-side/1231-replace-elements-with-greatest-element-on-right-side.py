class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        a = arr[-1]
        arr[-1] = -1
        for i in range(len(arr)-2, -1, -1):
            b = arr[i]
            arr[i] = a
            a = max(a, b)
            print(a, b)
        return arr