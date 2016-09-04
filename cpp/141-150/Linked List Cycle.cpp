/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr)
            return false;
        
        ListNode *first = head, *second = head->next;
        
        while (second != nullptr) {
            if (first == second)
                return true;
            first = first->next;
            second = second->next;
            if (second != nullptr)
                second = second->next;
        }
        
        return false;
    }
};
