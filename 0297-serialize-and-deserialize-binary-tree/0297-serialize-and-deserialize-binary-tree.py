# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:
    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        if root == None:
            return "#"
        
        return str(root.val) + "," + self.serialize(root.left) + "," + self.serialize(root.right)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        values = data.split(",")
        self.index = 0

        def preorder():
            if values[self.index] == "#":
                self.index += 1
                return None
            
            root = TreeNode(int(values[self.index]))
            self.index += 1

            root.left = preorder()
            root.right = preorder()

            return root
        
        return preorder()
        

# Your Codec object will be instantiated and called as such:
# ser = Codec()
# deser = Codec()
# ans = deser.deserialize(ser.serialize(root))