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
public:
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        int ans = root->val;
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t == nullptr) {
                if (!q.empty()) { ans = q.front()->val; q.push(nullptr); }
            } else {
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return ans;
    }
};
