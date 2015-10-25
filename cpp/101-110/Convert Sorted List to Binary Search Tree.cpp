/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
    ListNode *mylist;
    
    int len(ListNode *head)
    {
        int l = 0;
        while(head) {
            l++;
            head = head->next;
        }
        return l;
    }
    
    TreeNode *help(int n)
    {
        if(n == 0) return nullptr;
        TreeNode *l = help(n/2);
        TreeNode *newnode = new TreeNode(mylist->val);
        newnode->left = l;
        mylist = mylist->next;
        newnode->right = help(n - n/2 - 1);
        return newnode;
    }
    
public:
    TreeNode *sortedListToBST(ListNode *head) {
        this->mylist = head;
        return help(len(head));
    }
};