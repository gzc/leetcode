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
    ListNode *rotateRight(ListNode *head, int k) {
        if(!head || !head->next || !k)
            return head;
        
        int len = 1;
        ListNode *tail(head), *head2(head);
        while (tail && tail->next) {
            len++;
            tail = tail->next;
        }
        k = k % len;
        if(!k) return head;
        
        int n = len-k;
        while(--n)
            head2 = head2->next;
        ListNode *tmp = head2->next;
        head2->next = nullptr;
        head2 = tmp;
        
        tail->next = head;
        
        return head2;
    }
};
