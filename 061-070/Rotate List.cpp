class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        
        
        if(!head || !head->next || !k)
            return head;
        
        int len = 0;
        ListNode *tail(head), *head2(head);
        while(tail)
        {
            len++;
            tail = tail->next;
        }
        k = k % len;
        if(!k)
            return head;
        
        int n = len-k;
        while(--n)
            head2 = head2->next;
        ListNode *tmp = head2->next;
        head2->next = NULL;
        head2 = tmp;
        while(tmp->next)
            tmp = tmp->next;
        tmp->next = head;
        
        
        return head2;
        
        
    }
};