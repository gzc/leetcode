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
    
    void help(TreeNode* root, string path, vector<string>&paths)
    {
        path = path+to_string(root->val);
        if(root->left)
            help(root->left, path+"->", paths);
        if(root->right)
            help(root->right, path+"->", paths);
        if(!root->left && !root->right)
            paths.push_back(path);
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res;
        if(root == nullptr) return res;
        help(root, "", res);
        return res;
    }
};