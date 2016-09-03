class Solution {
    
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr) return false;
        if (root->left == nullptr && root->right == nullptr && sum == root->val) return true;
        return hasPathSum(root->left,sum - root->val) || hasPathSum(root->right,sum - root->val);
    }
};
