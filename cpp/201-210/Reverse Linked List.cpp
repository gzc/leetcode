class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode *tmp(NULL),*prev(NULL);
        while(head)
        {
            tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
};
