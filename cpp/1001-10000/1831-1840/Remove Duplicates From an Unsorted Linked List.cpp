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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode sudo_head(-1);
        
        unordered_map<int, int> mymap;
        for (ListNode* tmp = head; tmp != nullptr; tmp = tmp->next) {
            mymap[tmp->val]++;
        }
        
        ListNode* p = &sudo_head;
        for (ListNode* tmp = head; tmp != nullptr; tmp = tmp->next) {
            if (mymap[tmp->val] > 1) {
                continue;
            }
            
            p->next = tmp;
            p = tmp;
        }
        p->next = nullptr;
        
        return sudo_head.next;
    }
};
