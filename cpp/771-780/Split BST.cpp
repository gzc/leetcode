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
    vector<TreeNode*> splitBST(TreeNode* root, int V) {
        if (root == nullptr) {
            return vector<TreeNode*> {nullptr, nullptr};
        } else if (root->val <= V) {
            vector<TreeNode*> result = splitBST(root->right, V);
            root->right = result[0];
            result[0] = root;
            return result;
        } else {
            vector<TreeNode*> result = splitBST(root->left, V);
            root->left = result[1];
            result[1] = root;
            return result;
        }
    }
};
