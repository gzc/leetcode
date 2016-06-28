/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
    ListNode* reverseList(ListNode* head) {
        
        ListNode *tmp(NULL),*prev(NULL);
        while(head)
        {
            tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }
        return prev;
    }
    
public:
    ListNode* plusOne(ListNode* head) {
        
        ListNode* tail = reverseList(head);
        ListNode* tmptail = tail;
        
        int add = 1;
        
        while(tail) {
            
            if(add != 1) break;
            
            if(tail->val < 9) {
                tail->val++;
                break;
            } else {
                tail->val = 0;
                add = 1;
                if(tail->next) {
                    tail = tail->next;
                } else {
                    ListNode *newtail = new ListNode(1);
                    tail->next = newtail;
                    break;
                }
            }
            
        }
        
        return reverseList(tmptail);
        
    }
};
