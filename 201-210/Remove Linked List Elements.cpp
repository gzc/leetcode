#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;


struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* removeElements(struct ListNode* head, int val) {
    
    while(head && head->val == val) head = head->next;
    struct ListNode* result = head;
    
    while(head && head->next)
    {
        if(head->next->val == val)
            head->next = head->next->next;
        else
            head = head->next;
    }
    
    return result;
}

int main()
{
    return 0;
}