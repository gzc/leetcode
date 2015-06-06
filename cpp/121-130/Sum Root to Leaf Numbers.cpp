class Solution {
    
    int help(TreeNode *root, int pVal)
    {
        if(!root->left && !root->right)
            return root->val + 10*pVal;
            
        root->val += 10*pVal;
        
        if(root->left && root->right)
            return help(root->left, root->val)+help(root->right, root->val);
        else if(root->left && !root->right)
            return help(root->left, root->val);
        else
            return help(root->right, root->val);
    }
    
public:
    int sumNumbers(TreeNode *root) {
        
        if(!root) return 0;
        
        return help(root, 0);
        
    }
};
