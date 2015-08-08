class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    
    # @param {TreeNode} root
    # @return {integer}
    def maxPathSum(self, root):
        Solution.result = -10000000
        self.help(root)
        return Solution.result
    
    def help(self,root):
        if not root:
            return 0
        l = self.help(root.left)
        r = self.help(root.right)
        if l < 0:
            l = 0
        if r < 0:
            r = 0
        tmp = l + r + root.val
        Solution.result = max(Solution.result, tmp)
        tmp = root.val + max(l, r)
        return tmp


root = TreeNode(1);
l = TreeNode(2);
root.left = l
S = Solution()
print S.maxPathSum(root)