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
    
    int dfs(TreeNode* root, int& ans) {
        if (!root) return 0;
        int leftD = dfs(root->left, ans);
        int rightD = dfs(root->right, ans);
        
        ans = max(ans, 1 + leftD + rightD);
        return max(leftD, rightD) + 1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int ans = 0;
        dfs(root, ans);
        return ans - 1;
    }
};
