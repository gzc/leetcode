class Solution {
    
    TreeNode *help(vector<int>::iterator it1, vector<int>::iterator it2)
    {
        if(it1 == it2)
            return new TreeNode(*it1);
        else if(it1 > it2)
            return NULL;
        
        vector<int>::iterator midit = it1+(it2-it1)/2;
        TreeNode *node = new TreeNode(*midit);
        node->left = help(it1,midit-1);
        node->right = help(midit+1, it2);
        return node;
    }
    
public:
    TreeNode *sortedListToBST(ListNode *head) {
        
        if(!head) return NULL;
        
        vector<int> con;
        while(head)
        {
            con.push_back(head->val);
            head = head->next;
        }
        
        return help(con.begin(), con.end()-1);
        
    }
};
