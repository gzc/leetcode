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
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int result = 0;
        vector<pair<TreeNode*, int>> trees;
        trees.push_back({root, 0});
        while (!trees.empty()) {
            auto left = trees.front();
            auto right = trees.back();
            result = max(result, right.second - left.second + 1);
            vector<pair<TreeNode*, int>> temp;
            for (const auto& ele : trees) {
                TreeNode *node = ele.first;
                int v = ele.second;
                if (node->left) {
                    temp.push_back({node->left, 2*v});
                } 
                if (node->right) {
                    temp.push_back({node->right, 2*v+1});
                }
            }
            trees = temp;
        }
        return result;
    }
};
