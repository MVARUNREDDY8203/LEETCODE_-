# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def splitListToParts(self, head: Optional[ListNode], k: int) -> List[Optional[ListNode]]:
        curr = head
        n = 0
        while (curr is not None):
            curr = curr.next
            n += 1
        
        npp = n // k
        rem = n % k

        print(npp)

        ans = []
        curr = head
        for i in range(k):
            
            curr_npp = npp
            if rem > 0:
                curr_npp += 1
                rem -= 1
            
            idx = 1
            curr_head = curr if curr is not None else None
            while idx < curr_npp and curr_head:
                curr = curr.next
                idx += 1
            
            new_curr = curr.next if curr is not None else None
            if curr is not None:
                curr.next = None
            ans.append(curr_head)
            curr = new_curr
        return ans
