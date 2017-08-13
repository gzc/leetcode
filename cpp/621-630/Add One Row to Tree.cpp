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
    void dfs(TreeNode* root, TreeNode* parent, int v, int d, bool left) {
        if (root == nullptr && d > 1) return;
        if (d == 1) {
            TreeNode* node = new TreeNode(v);
            if (left) {
                node->left = root;
                parent->left = node;
            } else {
                node->right = root;
                parent->right = node;
            }
            return;
        }
        dfs(root->left, root, v, d - 1, true);
        dfs(root->right, root, v, d - 1, false);
    }
public:
    TreeNode* addOneRow(TreeNode* root, int v, int d) {
        if (d == 1) {
            TreeNode* newRoot = new TreeNode(v);
            newRoot->left = root;
            return newRoot;
        }
        dfs(root, nullptr, v, d, true);
        return root;
    }
};
