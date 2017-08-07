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
    bool found;
    
    void dfs(TreeNode* root, unordered_set<int>& myset, int k) {
        if (root == nullptr) return;
        if (found) return;
        if (myset.count(k - root->val) > 0) {
            found = true;
            return;
        }
        
        myset.insert(root->val);
        dfs(root->left, myset, k);
        dfs(root->right, myset, k);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        found = false;
        unordered_set<int> myset;
        dfs(root, myset, k);
        return found;
    }
};
