#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        
        ListNode *forward(head), *head_backup(head);
        
        while(forward && n--) forward = forward->next;
        if(n == 0) return head_backup->next;
        while(forward->next)
        {
            forward = forward->next;
            head = head->next;
        }
        ListNode *tail = head->next->next;
        head->next = tail;
        
        return head_backup;
    }
};

int main()
{
    Solution s;
    
    ListNode *n1 = new ListNode(1);
    ListNode *n2 = new ListNode(2);
    ListNode *n3 = new ListNode(3);
    ListNode *n4 = new ListNode(4);
    ListNode *n5 = new ListNode(5);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    ListNode *head = s.removeNthFromEnd(n1, 5);
    
    while(head)
    {
        cout << head->val << endl;
        head = head->next;
    }
    
    return 0;
}