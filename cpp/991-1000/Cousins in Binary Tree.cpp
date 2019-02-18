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
    
    // {parent, depth}
    bool getPD(TreeNode* root, int v, pair<TreeNode*, int>* res, int depth, TreeNode* parent) {
        if (root == nullptr) return false;
        if (root->val == v) {
            res->first = parent;
            res->second = depth;
            return true;
        }
        bool flag = getPD(root->left, v, res, depth+1, root);
        if (flag) return true;
        flag = getPD(root->right, v, res, depth+1, root);
        return flag;
    }
    
public:
    bool isCousins(TreeNode* root, int x, int y) {
        pair<TreeNode*, int> left, right;
        getPD(root, x, &left, 0, nullptr);
        getPD(root, y, &right, 0, nullptr);
        if (left.second != right.second) return false;
        if (left.first == right.first) return false;
        return true;
    }
};
