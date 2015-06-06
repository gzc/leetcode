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
    ListNode *reverseKGroup(ListNode *head, int k) {
        
        if(!head || !head->next || k == 1) return head;
        ListNode *result(NULL), *_head(NULL), *_previous_head(NULL);
        
        while(1)
        {
            _head = head;
            
            for(int i = 1;i < k;i++)
            {
                head = head->next;
                if(!head)
                {
                    if(!_previous_head) return _head;
                    else _previous_head -> next = _head;
                    return result;
                }
            }
            if(_previous_head)_previous_head ->next = head;
            if(!result) result = head;
                
            _previous_head = _head;
            
            
            ListNode *tmp1(_head->next), *tmp2(NULL);
            for(int i = 1;i < k;i++)
            {
                tmp2 = tmp1->next;
                tmp1->next = _head;
                _head = tmp1;
                tmp1 = tmp2;
            }
            
            if(!tmp2)
            {
                _previous_head -> next = NULL;
                break;
            }
            head = tmp2;
            
        }
        
        return result;
        
    }
    
};

int main()
{
    Solution s;
    
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    //ListNode *n3 = new ListNode(3);
    //ListNode *n4 = new ListNode(4);
    //ListNode *n5 = new ListNode(10);
    n1->next = n2;
    //n2->next = n3;
    //n3->next = n4;
    //n4->next = n5;
    
    ListNode *head = s.reverseKGroup(n1, 3);
    while(head)
    {
        cout << ":" << head->val << endl;
        head = head->next;
    }
    
    
    return 0;
}