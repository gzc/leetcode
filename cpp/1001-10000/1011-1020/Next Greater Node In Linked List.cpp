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
    vector<int> nextLargerNodes(ListNode* head) {
        int current_index = 0;
        vector<int> ans(10001, 0);
        stack<pair<int, int>> mystack;
        
        while (head) {
            while (!mystack.empty() && mystack.top().second < head->val) {
                pair<int, int> e = mystack.top();
                mystack.pop();
                ans[e.first] = head->val;
            }
            mystack.push({current_index, head->val});
            head = head->next;
            current_index++;
        }
        
        while (!mystack.empty()) {
            pair<int, int> e = mystack.top();
            mystack.pop();
            ans[e.first] = 0;
        }
        
        ans.resize(current_index);
        return ans;
    }
};
