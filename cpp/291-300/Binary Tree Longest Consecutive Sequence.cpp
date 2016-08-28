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
    
    int result;
    
    void help(TreeNode* root, int h) {
        result = max(result, h);
        
        if (root->left) {
            if (root->val == root->left->val -1)
                help(root->left, h+1);
            else
                help(root->left, 1);
        }
        if (root->right) {
            if (root->val == root->right->val -1)
                help(root->right, h+1);
            else
                help(root->right, 1);
        }
    }
    
public:
    int longestConsecutive(TreeNode* root) {
        if(!root) return 0;
        help(root, 1);
        return result;
    }
};
