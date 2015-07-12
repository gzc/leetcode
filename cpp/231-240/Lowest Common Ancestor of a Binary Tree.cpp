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
    
    bool find;
    TreeNode* result;
    
    bool help(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if(!root) return false;
        
        bool f1 = help(root->left, p, q);
        bool f2 = help(root->right, p, q);
        if(f1 && f2 && !find) {
            result = root;
            find = true;
        }
        if( (root == p || root == q) && (f1 || f2) && !find)
        {
            result = root;
            find = true;
        }
        return (f1 || f2 || root == p || root == q);
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        help(root, p, q);
        return result;
    }
};