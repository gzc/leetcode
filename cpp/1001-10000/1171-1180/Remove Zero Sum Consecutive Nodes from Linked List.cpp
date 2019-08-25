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
    ListNode* removeZeroSumSublists(ListNode* head) {
        map<int, ListNode*> mymap;
        
        ListNode* phead = new ListNode(0);
        mymap[0] = phead;
        phead->next = head;
        int sum = 0;
        while (head) {
            sum += head->val;

            if (mymap.count(sum) > 0) {
                ListNode* prev = mymap[sum];
                ListNode* deleted = prev->next;
                int mysum = sum;
                while (deleted != head) {
                    mysum += deleted->val;
                    mymap.erase(mysum);
                    deleted = deleted->next;
                }

                prev->next = head->next;
            } else {
                mymap[sum] = head;
            }
            
            head = head->next;
        }
        
        return phead->next;
    }
};
