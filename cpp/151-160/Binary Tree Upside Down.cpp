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

public:

    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (!root || !root->left) return root;
        TreeNode* cur_left = root->left;
        TreeNode* cur_right = root->right;
        TreeNode* new_root = upsideDownBinaryTree(root->left);
        cur_left->right = root;
        cur_left->left = cur_right;
        root->left = nullptr;
        root->right = nullptr;
        return new_root;
    }
    
};
