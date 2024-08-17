# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
        

    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        seen = collections.defaultdict(int)
        ans = []
        
        def serialize(root):
            if root is None:
                return "#"

            curr_subtree = str(root.val) + "," + serialize(root.left) + "," + serialize(root.right)

            if curr_subtree in seen:
                if seen[curr_subtree] < 2:
                    print(curr_subtree)
                    ans.append(root)
            
            seen[curr_subtree] += 1

            return curr_subtree

        serialize(root)
        return ans
        
        