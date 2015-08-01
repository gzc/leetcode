# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    # @param {ListNode} head
    # @return {boolean}
    def isPalindrome(self, head):
        if not head or not head.next:
            return True
        
        slow = fast = head
        while fast.next and fast.next.next:
            slow = slow.next
            fast = fast.next.next
        fast = self.reverse(slow.next)
        
        while fast:
            if head.val != fast.val:
                return False
            fast = fast.next
            head = head.next
        
        return True
    
    
    def reverse(self, head):
        prev = tmp = None
        while head:
            tmp = head.next
            head.next = prev
            prev = head
            head = tmp
        return prev