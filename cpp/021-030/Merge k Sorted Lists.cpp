class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        auto cmp = [] (ListNode *n1, ListNode *n2) {
            return n1->val >= n2->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> qs(cmp);
        for (int i = 0;i < lists.size();i++)
            if (lists[i]) 
                qs.push(lists[i]);
        if (qs.empty()) return nullptr;
        ListNode* head(qs.top()), *backup(head);
        
        while (!qs.empty()) {
            ListNode *node = qs.top();
            qs.pop();
            if(node->next) qs.push(node->next);
            head->next = qs.top();
            head = head->next;
        }
        head->next = nullptr;
        return backup;
    }
};
