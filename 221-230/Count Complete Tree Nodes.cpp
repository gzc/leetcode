class Solution {

    int help(TreeNode *root, int h)
    {
        
        if(!root) return 0;
        
        int tmp(0);
        TreeNode *p = root;
        while(p)
        {
            tmp++;
            p = p->right;
        }
        if(tmp == h)
            return (int)pow(2, h) - 1;
        else
            return 1+help(root->left, h-1) + help(root->right, h-1);
    }
    
public:
    int countNodes(TreeNode* root) {
        
        if(!root) return 0;
        int height(0);
        TreeNode *p(root);
        while(p)
        {
            p = p->left;
            height++;
        }
        
        return help(root, height);
    }
};
