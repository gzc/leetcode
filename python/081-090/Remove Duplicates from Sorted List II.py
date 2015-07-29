# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def deleteDuplicates(self, head):
        nhead = ListNode(0)
        prev = -2**31
        res = nhead
        
        while head:
            if head.val != prev and (not head.next or head.val != head.next.val) :
                nhead.next = head
                nhead = head
            prev = head.val
            head = head.next
        
        nhead.next = None
        return res.next