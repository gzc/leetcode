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
    
        while True:
            cur = root
            pre = None
            while cur:
                if cur.left:
                    if not pre:
                        pre = cur.left
                        root = pre
                    else:
                        pre.next = cur.left
                        pre = pre.next
            
                if cur.right:
                    if not pre:
                        pre = cur.right
                        root = pre
                    else:
                        pre.next = cur.right
                        pre = pre.next
        
                            cur = cur.next
                                
                                if not pre:
                                break