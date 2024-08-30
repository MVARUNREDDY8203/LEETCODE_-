"""
# Definition for a Node.
class Node:
    def __init__(self, val: Optional[int] = None, children: Optional[List['Node']] = None):
        self.val = val
        self.children = children
"""

class Solution:
    def postorder(self, root: 'Node') -> List[int]:
        ans = []
        def util(root):
            if root is None:
                return
            for child in root.children:
                util(child)
            ans.append(root.val)
        util(root)
        return ans