#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <stack>
#include <string>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        
        ListNode *node(head);
        while(node && node->next)
        {
            if (node->val == node->next->val)
                node->next = node->next->next;
            else
                node = node->next;
        }
        
        return head;
    }
    
};

int main()
{
    Solution s;
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(2);
    n1->next = n2;
    n2->next = n3;
    
    ListNode *head = s.deleteDuplicates(n1);
    
    while(head)
    {
        cout << head->val << " ";
        head = head->next;
    }
}