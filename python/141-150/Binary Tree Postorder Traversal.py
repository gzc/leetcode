# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {integer[]}
    def postorderTraversal(self, root):
        v = []
        if not root:
            return v
        
        stacks = []
        stacks.append(root)
        
        while len(stacks) > 0:
            root = stacks[-1]
            del stacks[-1]
            v.append(root.val)
            
            if root.left:
                stacks.append(root.left)
            if root.right:
                stacks.append(root.right)
        
        v.reverse()
    return v