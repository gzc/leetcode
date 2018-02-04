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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        vector<int> ans;
        if (!root) return ans;
        int current = INT_MIN;
        while (!q.empty()) {
            TreeNode* t = q.front();
            q.pop();
            if (t == nullptr) {
                ans.push_back(current);
                current = INT_MIN;
                if (!q.empty()) {
                    q.push(nullptr);
                }
            } else {
                current = max(current, t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return ans;
    }
};
