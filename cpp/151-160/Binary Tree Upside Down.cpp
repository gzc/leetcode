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
    
    TreeNode* help(TreeNode* root, TreeNode *p, TreeNode *r)
    {
        TreeNode* nextroot = root->left;
        TreeNode* si = root->right;
        
        TreeNode * check = root->left;
        root->left = r;
        root->right = p;
        
        if(!check) return root;
        
        return help(nextroot, root, si);
    }
    
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(!root) return root;
        if(!root->left) return root;
        
        TreeNode* res = help(root->left, root, root->right);
        root->left = nullptr;
        root->right = nullptr;
        return res;
    }
};