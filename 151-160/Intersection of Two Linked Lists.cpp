class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *head1(headA),*head2(headB);
        int len1(0),len2(0);
        while(head1)
        {
            len1++;
            head1 = head1->next;
        }
        while(head2)
        {
            len2++;
            head2 = head2->next;
        }
        int d = abs(len1-len2);
        if(len1 > len2)
            while(d--)
                headA = headA->next;
        if(len1 < len2)
            while(d--)
                headB = headB->next;
        while(headA != headB)
        {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
