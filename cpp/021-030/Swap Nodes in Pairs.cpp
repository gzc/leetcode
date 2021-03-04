class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        
        ListNode* new_head = head->next;
        
        head->next = swapPairs(new_head->next);
        new_head->next = head;
        
        return new_head;
    }
};
