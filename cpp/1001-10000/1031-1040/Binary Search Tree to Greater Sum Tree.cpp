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
    
    void dfs(TreeNode* root, int& v) {
        if (!root) return;
        dfs(root->right, v);
        v += root->val;
        root->val = v;
        dfs(root->left, v);
    }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        int v = 0;
        dfs(root, v);
        return root;
    }
};
