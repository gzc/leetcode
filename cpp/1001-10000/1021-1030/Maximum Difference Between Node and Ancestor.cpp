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
    
    int dfs(TreeNode* root, int min_, int max_) {
        if (!root) return 0;
        
        int current = max(abs(min_ - root->val), abs(max_ - root->val));
        
        min_ = min(min_, root->val);
        max_ = max(max_, root->val);
        
        return max(current, max(dfs(root->left, min_, max_), dfs(root->right, min_, max_)));
    }
    
public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root->val, root->val);
    }
};
