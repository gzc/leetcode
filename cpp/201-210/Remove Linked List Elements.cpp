class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* res = new ListNode(1);
        res->next = head;
        ListNode* backup = res;
        
        //res -> head -> head->next
        while (head) {
            if (head->val == val)
                res->next = head->next;
            else 
                res = head;
            head = head->next;
        }
        
        return backup->next;
    }
};
