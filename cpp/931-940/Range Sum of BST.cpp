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
    
    int dfs(TreeNode* root, int L, int R) {
        if (root == nullptr) return 0;
        int v = dfs(root->left, L, R) + dfs(root->right, L, R);
        if (root->val >= L && root->val <= R) return v + root->val;
        else return v;
        
    }
    
public:
    int rangeSumBST(TreeNode* root, int L, int R) {
        return dfs(root, L, R);
    }
};
