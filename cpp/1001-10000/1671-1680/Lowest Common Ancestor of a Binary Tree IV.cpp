/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    TreeNode* lowestCommonAncestor(TreeNode* root, const set<TreeNode*>& nodes_set) {
        if (root == nullptr) {
            return nullptr;
        }
    
        if (nodes_set.count(root) > 0) {
            return root;
        }
    
        TreeNode* l = lowestCommonAncestor(root->left, nodes_set);
        TreeNode* r = lowestCommonAncestor(root->right, nodes_set);
    
        if (l && r) {
            return root;
        }
    
        return l ? l : r;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, vector<TreeNode*> &nodes) {
        set<TreeNode*>nodes_set(nodes.begin(), nodes.end());
        return lowestCommonAncestor(root, nodes_set);
    }
};
