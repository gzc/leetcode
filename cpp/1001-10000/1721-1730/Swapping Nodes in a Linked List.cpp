/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* l1 = head, *l2 = head;
        
        for (int i = 1; i < k; i++) {
            l1 = l1->next;
        }
        
        int len = 0;
        while (l2 != nullptr) {
            len++;
            l2 = l2->next;
        }
        l2 = head;
        
        for (int i = 1; i <= (len - k); i++) {
            l2 = l2->next;
        }
        
        swap(l1->val, l2->val);
        
        return head;
    }
};
