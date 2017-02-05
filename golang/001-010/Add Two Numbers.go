/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    carry := 0
    var virtual_head *ListNode = new(ListNode)
    copy_virtual_head := virtual_head
    for l1 != nil || l2 != nil || carry > 0 {
        v1 := 0
        v2 := 0
        if l1 != nil { 
            v1 = l1.Val
            l1 = l1.Next
        }
        if l2 != nil {
            v2 = l2.Val
            l2 = l2.Next
        }
        tmp := v1 + v2 + carry
        carry = tmp/10
        var new_node *ListNode = new(ListNode)
        new_node.Val = tmp%10;
        virtual_head.Next = new_node
        virtual_head = new_node
    }
    return copy_virtual_head.Next
}
