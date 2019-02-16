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
    int ans;
    
    // {num of nodes, num of coins}
    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr) return {0, 0};
        auto leftRes = dfs(root->left);
        auto rightRes = dfs(root->right);
        if (leftRes.first > leftRes.second) {
            ans += (leftRes.first - leftRes.second);
        }
        if (rightRes.first > rightRes.second) {
            ans += (rightRes.first - rightRes.second);
        }
        int node = leftRes.first + rightRes.first + 1;
        int coin = leftRes.second + rightRes.second + root->val;
        if (coin > node) ans += (coin - node);
        
        return {node, coin};
    }
    
public:
    int distributeCoins(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
};
