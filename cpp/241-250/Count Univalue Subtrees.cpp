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
    
    bool help(TreeNode* root)
    {
        if(!root) return true;
        if(!root->left && !root->right) {result++;return true;}
        bool left = help(root->left);
        bool right = help(root->right);
        if(!left || !right) return false;
        if(root->left && root->right) {
            if(root->left->val == root->val && root->right->val == root->val) {
                result++;
                return true;
            } else return false;
        }
        else if(root->left && root->left->val == root->val) {
            result++;
            return true;
        }
        else if(root->right && root->right->val == root->val) {
            result++;
            return true;
        }
        return false;
    }
    
public:
    int countUnivalSubtrees(TreeNode* root) {
        result = 0;
        help(root);
        return result;
    }
};