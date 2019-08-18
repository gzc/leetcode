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
    
    map<int, int> mymap;
    
    void dfs(TreeNode* root, int level) {
        if (root == nullptr) return;
        mymap[level] += root->val;
        dfs(root->left, level+1);
        dfs(root->right, level+1);
    }
    
public:
    int maxLevelSum(TreeNode* root) {
        int level = 1;
        int max_sum = INT_MIN;
        dfs(root, 1);
        
        for (auto& it : mymap) {
            if (it.second > max_sum) {
                max_sum = it.second;
                level = it.first;
            }
        }
        
        return level;
    }
};
