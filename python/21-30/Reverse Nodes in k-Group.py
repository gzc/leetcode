#!/usr/bin/env python
# coding=utf-8

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @param {integer} k
    # @return {ListNode}
    def reverseKGroup(self, head, k):
        if not head or k < 2:
            return head

        ret = head
        for i in range(k-1):
            ret = ret.next
            if not ret:
                return head

        prev,cur = None,head
        for i in range(k):
            tmp = cur.next
            cur.next = prev
            prev = cur
            cur = tmp

        head.next = self.reverseKGroup(cur, k)
        return ret