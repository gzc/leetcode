# Definition for binary tree with next pointer.
# class TreeLinkNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
#         self.next = None

class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if not root:
            return
        
        while root.left:
            cur = root
            pre = None
            while cur:
                if pre:
                    pre.next = cur.left
                cur.left.next = cur.right
                pre = cur.right
                cur = cur.next
            root = root.left