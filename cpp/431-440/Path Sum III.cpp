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
    int res;
    
    void dfs(TreeNode* root, map<int, int>& mymap, int currentSum, int target) {
        if (!root) return;
        currentSum += root->val;
        res += mymap[currentSum - target];
        mymap[currentSum]++;
        dfs(root->left, mymap, currentSum, target);
        dfs(root->right, mymap, currentSum, target);
        mymap[currentSum]--;
    }
    
public:
    int pathSum(TreeNode* root, int sum) {
        res = 0;
        map<int, int> mymap;
        mymap[0] = 1;
        dfs(root, mymap, 0, sum);
        return res;
    }
};
