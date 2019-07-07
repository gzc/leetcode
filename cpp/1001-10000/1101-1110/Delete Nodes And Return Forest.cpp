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
    
    vector<TreeNode*> ans;
    
    TreeNode* dfs (TreeNode* root, set<int>& to_deleted, bool is_root) {
        
        if (root == nullptr) {
            return nullptr;
        }
        
        if (to_deleted.count(root->val) > 0) {
            dfs(root->left, to_deleted, true);
            dfs(root->right, to_deleted, true);
            return nullptr;
        }
        
        root->left = dfs(root->left, to_deleted, false);
        root->right = dfs(root->right, to_deleted, false);
        
        if (is_root) ans.push_back(root);
        
        return root;
    }
    
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> to_deleted(to_delete.begin(), to_delete.end());
        dfs(root, to_deleted, true);
        return ans;
    }
};
