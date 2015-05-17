class Solution {
    
    int result;
    
    int help(TreeNode *root)
    {
        if(!root) return 0;

        int l = help(root->left);
        int r = help(root->right);
        l = l > 0 ? l : 0;
        r = r > 0 ? r : 0;
        int tmp = l + r + root->val;
        result = max(result, tmp);
        tmp = root->val + max(l, r);
        return tmp;
    }
    
public:
    int maxPathSum(TreeNode *root) {
        result = INT_MIN;
        help(root);
        return result;
    }
};
