class Solution {
    
    int help(TreeNode *root, bool& flag) {
        if (root == nullptr) return 0;
        int left = 1 + help(root->left, flag);
        int right = 1 + help(root->right, flag);
        
        if (abs(left - right) > 1) flag = false;
        return max(left, right);
    }
    
public:
    bool isBalanced(TreeNode *root) {
        bool flag = true;
        help(root, flag);
        return flag;
    }
};
