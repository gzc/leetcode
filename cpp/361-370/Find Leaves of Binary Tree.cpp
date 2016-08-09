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
    
    int dfs(TreeNode* root, vector<vector<int>> &myvec) {
        if (root == nullptr) return 0;
        int ldepth = dfs(root->left, myvec);
        int rdepth = dfs(root->right, myvec);
        int depth = 1 + max(ldepth, rdepth);
        if (myvec.size() < depth) {
            myvec.resize(myvec.size()+1);
        }
        myvec[depth-1].push_back(root->val);
        return depth;
    }
    
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> myvec;
        dfs(root, myvec);
        return myvec;
    }
};
