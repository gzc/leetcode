/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
    ListNode* addToFront(int val, ListNode* head){
        ListNode* temp = new ListNode(val);
        temp->next = head;
        return temp;
    }
    
    int length(ListNode* head) {
        int len = 0;
        while (head) {
            len++;
            head = head->next;
        }
        return len;
    }
    
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = length(l1);
        int n2 = length(l2);
        int carry = 0;
        ListNode *curr1 = l1, *curr2 = l2, *res = nullptr;
        
        while (n1 > 0 || n2 > 0){
            int sum = 0;
            if( n1 >= n2 ){ sum += curr1->val; curr1=curr1->next; n1--;}
            if( n2 > n1 ){ sum += curr2->val; curr2=curr2->next; n2--;}
            res = addToFront( sum, res );
        }
        
        curr1 = res;
        res = nullptr;
        while( curr1 || carry) {
            int tmp = curr1 ? curr1->val : 0;
            tmp += carry;
            carry = tmp/10;
            res = addToFront(tmp%10, res);
            if (!curr1) break;
            curr2 = curr1; 
            curr1 = curr1->next;
            delete curr2;
        }
        
        return res;
    }
};
