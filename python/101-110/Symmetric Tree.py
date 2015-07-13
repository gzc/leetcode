# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import Queue

class Solution:
    # @param {TreeNode} root
    # @return {boolean}
    def isSymmetric(self, root):
        if not root:
            return True
        myqueue = Queue.Queue()
        myqueue.put(root.left)
        myqueue.put(root.right)
        
        while not myqueue.empty():
            left = myqueue.get();
            right = myqueue.get();
            if not left and not right:
                continue
            if left and not right:
                return False
            if right and not left:
                return False
            if left.val != right.val:
                return False
            
            myqueue.put(left.left)
            myqueue.put(right.right)
            myqueue.put(left.right)
            myqueue.put(right.left)
        
                return True