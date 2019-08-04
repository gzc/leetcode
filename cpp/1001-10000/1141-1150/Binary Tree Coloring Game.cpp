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
    
    int l_num_;
    int r_num_;
    
    int dfs(TreeNode* root, int x) {
        if (!root) return 0;
        
        int l = dfs(root->left, x);
        int r = dfs(root->right, x);
        
        if (root->val == x) {
            l_num_ = l;
            r_num_ = r;
            return 0;
        }
        
        return l + r + 1;
    }
    
public:
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        l_num_ = 0;
        r_num_ = 0;
        
        int l_p = dfs(root, x);
        
        return (l_num_ > n/2 || r_num_ > n/2 || l_p > n/2);
    }
};
