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
    
    void leftBoundary(TreeNode* root, vector<int>& nodes) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)) return;
        nodes.push_back(root->val);
        if(root->left == nullptr) leftBoundary(root->right, nodes);
        else leftBoundary(root->left, nodes);
    }
    
    void rightBoundary(TreeNode* root, vector<int>& nodes) {
        if(root == nullptr || (root->left == nullptr && root->right == nullptr)) return;
        if(root->right == nullptr) rightBoundary(root->left, nodes);
        else rightBoundary(root->right, nodes);
        nodes.push_back(root->val); // add after child visit(reverse)
    }
    
    void leaves(TreeNode* root, vector<int>& nodes) {
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) {
            nodes.push_back(root->val);
            return;
        }
        leaves(root->left, nodes);
        leaves(root->right, nodes);
    }
    
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> nodes;
        if (root == nullptr) return nodes;
        nodes.push_back(root->val);
        leftBoundary(root->left, nodes);
        leaves(root->left, nodes);
        leaves(root->right, nodes);
        rightBoundary(root->right, nodes);
        return nodes;
    }
};
