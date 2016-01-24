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
    ListNode* oddEvenList(ListNode* head) {
        
        ListNode* oddhead = new ListNode(0);
        ListNode* res = oddhead;
        
        ListNode* evenhead = new ListNode(0);
        ListNode* res2 = evenhead;
        
        int count(1);
        
        while(head) {
            if(count % 2 == 1) {
                oddhead -> next = head;
                oddhead = oddhead->next;
            } else {
                evenhead -> next = head;
                evenhead = evenhead->next;
            }
            head = head->next;
            count++;
        }
        
        evenhead->next = nullptr;
        oddhead -> next = res2 -> next;
        return res->next;
    }
};