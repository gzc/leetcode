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
    int dfs(TreeNode* root, int &result) {
        if (!root) return 0;
        int left = dfs(root->left, result);
        int right = dfs(root->right, result);
        result += abs(left - right);
        return left + right + root->val;
    }
public:
    int findTilt(TreeNode* root) {
        int result = 0;
        dfs(root, result);
        return result;
    }
};
