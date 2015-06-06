class Solution {

    bool flag;
    
    int help(TreeNode *root)
    {
        if(!root) return 0;
        int left = 1+help(root->left);
        int right = 1+help(root->right);
        
        if(abs(left - right) > 1) flag = false;
        return max(left, right);
    }
    
public:
    bool isBalanced(TreeNode *root) {
        flag = true;
        help(root);
        return flag;
    }
};
