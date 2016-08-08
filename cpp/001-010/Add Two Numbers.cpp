class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *pre = head;
        int carry = 0;
        
        while(l1 || l2 || carry) {
            int a = (l1 == NULL? 0 : l1->val);
            int b = (l2 == NULL? 0 : l2->val);
            int c = a + b + carry;
            carry = c > 9? 1 : 0;
            int v = c%10;
            ListNode *cur = new ListNode(v);
            pre->next = cur;
            pre = pre->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        return head->next;
    }
};
