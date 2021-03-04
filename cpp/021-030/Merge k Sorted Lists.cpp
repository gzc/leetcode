class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto cmp = [] (ListNode *n1, ListNode *n2) {
            return n1->val > n2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> nodes(cmp);
        for (ListNode *list : lists) {
            if (list != nullptr) {
                nodes.push(list);
            }
        }
        
        if (nodes.empty()) {
            return nullptr;
        }
        ListNode fake_head(0);
        ListNode* current = &fake_head;
        
        while (!nodes.empty()) {
            current->next = nodes.top();
            current = current->next;
            nodes.pop();
            if (current->next != nullptr) {
                nodes.push(current->next);
            }
        }
        
        return fake_head.next;
    }
};
