/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
    ListNode* dfs(ListNode* head, int len, int k) {
        if (len < k) return head;
        ListNode* tail = head;
        int kk = k;
        
        ListNode* prev = nullptr, *tmp = nullptr;
        while (kk > 0) {
            tmp = head->next;
            head -> next = prev;
            prev = head;
            head = tmp;
            kk--;
        }
        
        tail -> next = dfs(head, len - k, k);
        return prev;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* tmp = head;
        while (tmp) {
            len++;
            tmp = tmp->next;
        }
        
        return dfs(head, len, k);
    }
};
