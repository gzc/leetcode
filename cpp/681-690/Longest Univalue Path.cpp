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
    int res;
    
    int dfs(TreeNode* root) {
        if (root == nullptr) return 0;
        int left = root->left ? dfs(root->left) : 0;
        int right = root->right ? dfs(root->right) : 0;
        int temp = 0;
        int returnValue = 0;
        if (root->left && root->left->val == root->val) {
            temp += left;
            returnValue = max(returnValue, left);
        }
        if (root->right && root->right->val == root->val) {
            temp += right;
            returnValue = max(returnValue, right);
        }
        res = max(res, temp);
        return returnValue + 1;
    }
    
public:
    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return res;
    }
};
