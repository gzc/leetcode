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
    int numComponents(ListNode* head, vector<int>& G) {
        set<int> myset(G.begin(), G.end());
        int ans = 0;
        bool flag = false;
        
        while (head) {
            int v = head->val;
            if (myset.count(v) > 0) {
                if (!flag) {
                    flag = true;
                }
            } else {
                if (flag) {
                    ans++;
                }
                flag = false;
            }
            
            head = head->next;
        }
        if (flag) ans++;
        return ans;
    }
};
