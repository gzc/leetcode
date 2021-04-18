class Solution {
    
    int dfs(TreeNode *root, int& result) {
        if (root == nullptr) {
            return 0;
        }

        int l = max(0, dfs(root->left, result));
        int r = max(0, dfs(root->right, result));
        result = max(result, l + r + root->val);

        return root->val + max(l, r);
    }
    
public:
    int maxPathSum(TreeNode *root) {
        int result = INT_MIN;
        dfs(root, result);
        return result;
    }
};
