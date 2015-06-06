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
    ListNode *detectCycle(ListNode *head) {
        
        if(!head) return NULL;
        
        ListNode *first = head;
        ListNode *second = head->next;
        ListNode *terminal(NULL);
        ListNode *start2(NULL);
        while(second != NULL)
        {
            if(first == second) {
                terminal = first;
                start2 = first->next;
                break;
            }
            first = first->next;
            second = second->next;
            if(second != NULL)
                second = second->next;
        }
        
        if(terminal == NULL)
            return NULL;
        
        first = head;
        int l1 = 0;
        int l2 = 0;
        while(first != terminal)
        {
            first = first->next;
            l1++;
        }
        first = start2;
        while(first != terminal)
        {
            first = first->next;
            l2++;
        }
        
        int d = abs(l1-l2);
        first = head;
        if(l1 > l2)
            while(d > 0){
                d--;
                first = first->next;
            }
        else
            while(d>0){
                d--;
                start2 = start2->next;
            }
        
        while(first != start2){
            first = first->next;
            start2 = start2->next;
        }
        
        return first;
        
        
    }
};
