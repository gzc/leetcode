class Solution {
    
public:
    ListNode *insertionSortList(ListNode *head) {
        ListNode result(INT_MIN);

        while (head) {
            ListNode* iter = &result;
            while (iter->next && iter->next->val < head->val)
                iter = iter->next;
            ListNode* next = head->next;
            head->next = iter->next;
            iter->next = head;
            head = next;
        }

        return result.next;
    }

};
