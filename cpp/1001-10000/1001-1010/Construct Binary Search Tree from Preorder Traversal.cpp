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
    
    TreeNode* dfs(int& i, vector<int>& preorder, int lower, int upper) {
        if (i >= preorder.size()) return nullptr;
        
        int v = preorder[i];
        
        if (v < lower || v > upper) return nullptr;
        
        TreeNode* root = new TreeNode(v);
        
        i++;
        
        root->left = dfs(i, preorder, lower, v);
        
        root->right = dfs(i, preorder, v, upper);
        
        return root;
    }
    
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i = 0;
        return dfs(i, preorder, -99999999, 99999999);
    }
};
