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
    
    int height(TreeNode* root, int h) {
        if (root == nullptr) {
            return 0;
        }
        int hl = height(root->left, h + 1);
        int hr = height(root->right, h + 1);
        return max(hl, hr) + 1;
    }
    
    void dfs(TreeNode* root, vector<vector<string>>& result, int height, int pos, int base) {
        if (root == nullptr) return;
        result[height][pos] = to_string(root->val);
        dfs(root->left, result, height+1, pos - base/2, base/2);
        dfs(root->right, result, height+1, pos + base/2, base/2);
    }
    
public:
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root, 0);
        int cols = 1;
        for (int i = 2; i <= h; i++) {
            cols = cols * 2 + 1;
        }
        vector<vector<string>> result(h, vector<string>(cols, ""));
        
        dfs(root, result , 0, cols/2, (cols+1)/2);
        return result;
    }
};
