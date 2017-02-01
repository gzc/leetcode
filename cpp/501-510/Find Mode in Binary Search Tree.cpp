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
    
    void dfs(TreeNode* root, int& maximum_count, map<int, int>& mymap) {
        if (!root) return;
        int v = root->val;
        mymap[v]++;
        maximum_count = max(maximum_count, mymap[v]);
        dfs(root->left, maximum_count, mymap);
        dfs(root->right, maximum_count, mymap);
    }
    
public:
    vector<int> findMode(TreeNode* root) {
        map<int, int> mymap;
        vector<int> result;
        int maximum_count(0);
        dfs(root, maximum_count, mymap);
        for (auto it : mymap)
            if (it.second == maximum_count)
                result.push_back(it.first);
        return result;
    }
};
