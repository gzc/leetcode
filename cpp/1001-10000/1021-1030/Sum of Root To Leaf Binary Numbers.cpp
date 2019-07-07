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
    
    int dfs(TreeNode* root, int carry) {
        if (!root) return 0;
        if (!root->left && !root->right) {
            return 2*carry + root->val;
        }
        
        carry = 2 * carry + root->val;
        return dfs(root->left, carry) + dfs(root->right, carry);
    }
    
public:
    int sumRootToLeaf(TreeNode* root) {
        return dfs(root, 0);
    }
};
