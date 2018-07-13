/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
    int maxDeep;
    
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
    
    TreeNode* dfs(TreeNode* root, int deep) {
        if (!root) return nullptr;
        if (deep == maxDeep) return root;
        
        TreeNode* l = dfs(root->left, deep+1);
        TreeNode* r = dfs(root->right, deep+1);
        
        if (l && r) return root;
        if (l && !r) return l;
        if (r && !l) return r;
        return nullptr;
    }
    
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == nullptr) return nullptr;
        maxDeep = maxDepth(root);
        return dfs(root, 1);
    }
};
