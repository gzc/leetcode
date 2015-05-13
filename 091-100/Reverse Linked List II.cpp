class Solution {
public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int d = n - m;
        if(m == n) return head;
        int ttt = m;
        
        ListNode *answer = new ListNode(0);
        answer->next = head;
        
        while(--m > 1)
            head = head->next;
        ListNode *left = ttt == 1 ? answer : head;
        ListNode *r_head = left->next;
        
        head = r_head;
        ListNode *tmp = head->next;
        while(d-- > 0) {
            ListNode *n = tmp->next;
            tmp -> next = head;
            head = tmp;
            tmp = n;
        }

        left->next = head;
        r_head->next = tmp;
        
        return answer->next;
    }
};
