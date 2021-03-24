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
    
    pair<TreeNode*, int> dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return {nullptr, 0};
        }
    
        pair<TreeNode*, int> l_res = dfs(root->left, p, q);
        pair<TreeNode*, int> r_res = dfs(root->right, p, q);
        
        if (root == p || root == q) {
            return {root, 1 + l_res.second + r_res.second};
        }
    
        if (l_res.first && r_res.first) {
            return {root, 2};
        }
    
        return l_res.first ? l_res : r_res;
    }
        
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        pair<TreeNode*, int> res = dfs(root, p, q);
        if (res.second < 2) {
            return nullptr;
        }
        return res.first;
    }
};
