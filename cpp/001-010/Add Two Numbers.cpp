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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head = new ListNode(0);
        ListNode *pre = head;
        int add = 0;
        
        while(l1 || l2 || add) {
            int a = (l1 == NULL? 0 : l1->val);
            int b = (l2 == NULL? 0 : l2->val);
            int c = a + b + add;
            add = c > 9? 1 : 0;
            int v = c%10;
            ListNode *cur = new ListNode(0);
            cur->val = v;
            pre->next = cur;
            pre = pre->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }

        return head->next;
    }
};

int main()
{
    ListNode *a1 = new ListNode(2);
    ListNode *a2 = new ListNode(4);
    ListNode *a3 = new ListNode(3);
    ListNode *b1 = new ListNode(5);
    ListNode *b2 = new ListNode(6);
    ListNode *b3 = new ListNode(4);
    a1->next = a2;
    a2->next = a3;
    b1->next = b2;
    b2->next = b3;
    
    Solution s;
    ListNode *result = s.addTwoNumbers(a1, b1);
    
    while(result) {
        cout << result->val << endl;
        result = result->next;
    }
    
    return 0;
}
