#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        
        if(!head || !head->next) return head;
        ListNode *result = head->next, *_head(result);
        
        while(1)
        {
            ListNode *tmp = _head->next;
            _head -> next = head;
            if(!tmp)
            {
                head->next = NULL;
                break;
            }
            if(tmp->next)
                head->next = tmp->next;
            else
            {
                head->next = tmp;
                break;
            }
            head = tmp;
            _head = head->next;
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
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(10);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    
    ListNode *head = s.swapPairs(n1);
    while(head)
    {
        cout << head->val << endl;
        head = head->next;
    }
    
    
    return 0;
}