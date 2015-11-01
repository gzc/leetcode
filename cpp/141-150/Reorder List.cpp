class Solution {
    
    ListNode* reverse(ListNode *head)
    {
        ListNode *tmp = head->next;
        ListNode *p = nullptr;
        head->next = NULL;
        while (tmp)
        {
            p = tmp->next;
            tmp -> next = head;
            head = tmp;
            tmp = p;
        }
        return head;
    }
    
public:
    void reorderList(ListNode *head) {
        if(!head || !head->next) return;
        
        ListNode *head1 = head;
        ListNode *head2 = head->next;
        
        while(head2 && head2->next) {
            head1 = head1->next;
            head2 = head2->next->next;
        }

        head2 = head1 -> next;
        head1 -> next = nullptr;
        head1 = head;
        head2 = reverse(head2);

        ListNode *tmp = head1 -> next;
        while(head2){
            head1 -> next = head2;
            head1 = head2;
            head2 = tmp;
            tmp = head1->next;
        }
    }
};
