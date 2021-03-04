class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* head_copy = head;
        
        while (head_copy != nullptr) {
            head_copy = head_copy->next;
            len++;
        }
        
        if (n == len) {
            ListNode* new_head = head->next;
            delete head;
            return new_head;
        }
        
        head_copy = head;
        for (int i = 1; i < (len - n); i++) {
            head_copy = head_copy->next;
        }
        
        ListNode* to_delete = head_copy->next;
        head_copy->next = head_copy->next->next;
        delete to_delete;
        return head;
    }
};
