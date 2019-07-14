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
    
    pair<int, TreeNode*>  dfs(TreeNode* root) {
        if (root == nullptr) {
            return {0, root};
        }

        pair<int, TreeNode*> l_ans = dfs(root->left);
        pair<int, TreeNode*> r_ans = dfs(root->right);
        
        if (l_ans.first == r_ans.first) {
            return {l_ans.first+1, root};
        } else if (l_ans.first > r_ans.first) {
            return {l_ans.first+1, l_ans.second};
        } else {
            return {r_ans.first+1, r_ans.second};
        }
    }
    
public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root).second;
    }
};
