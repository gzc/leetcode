class Solution {
    
    int help(TreeNode *root)
    {
        if(!root->left && !root->right)
            return 1;
        else if(root->left && root->right)
            return 1+min(help(root->left), help(root->right));
        else if(!root->left && root->right)
            return 1+help(root->right);
        else
            return 1+help(root->left);
    }
    
public:
    int minDepth(TreeNode *root) {
        if(!root)
            return 0;
        return help(root);
    }
};
