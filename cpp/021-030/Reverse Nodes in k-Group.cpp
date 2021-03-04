class Solution {
    
    int length(ListNode* head) {
        int len = 0;
        while (head != nullptr) {
            head = head->next;
            len++;
        }
        return len;
    }
    
    ListNode* dfs(ListNode* head, int len, int k) {
        if (len < k) {
            return head;
        }
        ListNode* tail = head;
        
        ListNode* prev = nullptr, *tmp = nullptr;
        for (int i = 0; i < k; i++) {
            tmp = head->next;
            head -> next = prev;
            prev = head;
            head = tmp;
        }
        
        tail->next = dfs(head, len - k, k);
        return prev;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        return dfs(head, length(head), k);
    }
};
