/**
 * Definition for singly-linked list.
 * class ListNode(_x: Int = 0, _next: ListNode = null) {
 *   var next: ListNode = _next
 *   var x: Int = _x
 * }
 */
object Solution {
    def addTwoNumbers(l1: ListNode, l2: ListNode): ListNode = {
        def addTwoNumbersHelper(l1: ListNode, l2: ListNode, carry: Int): ListNode = {
            if (l1 == null && l2 == null) if (carry == 0) null else ListNode(carry)
            else if (l1 == null) addTwoNumbersHelper(ListNode(0), l2, carry)
            else if (l2 == null) addTwoNumbersHelper(l1, ListNode(0), carry)
            else ListNode((l1.x + l2.x + carry) % 10, addTwoNumbersHelper(l1.next, l2.next, (l1.x + l2.x + carry) / 10 ))
        }
        
        addTwoNumbersHelper(l1, l2, 0)
    }
}
