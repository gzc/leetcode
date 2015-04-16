#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        
        if(l1 == NULL) return l2;
        else if(l2 == NULL) return l1;
        
        ListNode *head = (l1->val <= l2->val) ? l1 : l2;
        ListNode *result = head;
        if(head == l1) l1 = l1->next;
        else l2 = l2->next;
        
        while(l1 != NULL || l2 != NULL)
        {
            if(l1 == NULL)
            {
                head->next = l2;
                break;
            } else if(l2 == NULL)
            {
                head->next = l1;
                break;
            }
            
            if(l1->val <= l2->val)
            {
                head->next = l1;
                head = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                head = l2;
                l2 = l2->next;
            }
        }
        
        return result;
    }
    
};

int main()
{
    Solution s;
    
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(7);
    ListNode *n5 = new ListNode(9);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    
    ListNode *n6 = new ListNode(4);
    ListNode *n7 = new ListNode(5);
    ListNode *n8 = new ListNode(6);
    ListNode *n9 = new ListNode(8);
    ListNode *n10 = new ListNode(10);
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n10;
    
    ListNode *head = s.mergeTwoLists(n1, n6);
    
    
    while(head)
    {
        cout << head->val << endl;
        head = head->next;
    }

    
    
    return 0;
}