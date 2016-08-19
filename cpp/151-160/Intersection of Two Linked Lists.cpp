class Solution {
    
    int getLen(ListNode *head) {
        int len(0);
        while (head) {
            head = head->next;
            len++;
        }
        return len;
    }
    
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = getLen(headA);
        int len2 = getLen(headB);
        if (len2 > len1) {
            swap(headA, headB);
            swap(len1, len2);
        }
        
        while (len1-- != len2) headA = headA->next;
        while (headA != headB) {
            headA = headA->next;
            headB = headB->next;
        }
        return headA;
    }
};
