# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        traversal_stack = []
        preorder = []
        curr = root
        
        while curr or traversal_stack:
            if curr:
                preorder.append(curr.val)
                traversal_stack.append(curr)
                curr = curr.right
            else:
                curr = traversal_stack.pop()
                curr = curr.left
        
        preorder.reverse()
        return preorder