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
    ListNode* middleNode(ListNode* head) {
        ListNode *slow(head), *fast(head->next);
        
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) fast = fast->next;
        }
        
        return slow;
    }
};
