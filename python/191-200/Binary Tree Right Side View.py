#!/usr/bin/env python
# coding=utf-8

class Solution:
    # @param {TreeNode} root
    # @return {integer[]}
    def rightSideView(self, root):
        items = []
        self.help(root, items, 0)
        return items
    
    def help(self, root, items, height):
        if not root:
            return
        if(height == len(items)):
            items.append(root.val)
        self.help(root.right, items, height+1)
        self.help(root.left, items, height+1)