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
        if(!head) return NULL;
        
        int prev(head->val);
        ListNode *result(head);
        head = head->next;
        ListNode *_head = result;
        
        while(head)
        {
            if(head->val != prev)
            {
                _head->next = head;
                _head = head;
                prev = head->val;
            }
            head = head->next;
        }
        _head->next = NULL;
        
        return result;
        
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