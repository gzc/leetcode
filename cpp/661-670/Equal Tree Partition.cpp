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
    set<int> myset;
    
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int sum = root->val + dfs(root->left) + dfs(root->right);
        myset.insert(sum);
        return sum;
    }
public:
    bool checkEqualTree(TreeNode* root) {
        if (!root) return false;
        int sum1 = dfs(root->left);
        int sum2 = dfs(root->right);
        int sum = root->val + sum1 + sum2;
        if (sum % 2 != 0) return false;
        int target = sum / 2;
        if (myset.count(target) > 0) return true;
        return false;
    }
};
