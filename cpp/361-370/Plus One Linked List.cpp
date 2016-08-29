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
        ListNode *tmp(nullptr), *prev(nullptr);
        while (head != nullptr) {
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
        int carry(1);
        while (tail || carry > 0) {
            if (tail->val + carry < 10) {
                tail->val ++;
                break;
            } else {
                tail->val = 0;
                if (tail->next != nullptr) {
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
