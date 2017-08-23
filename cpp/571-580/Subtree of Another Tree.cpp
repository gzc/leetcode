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
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root == nullptr) return "# ";
        else return to_string(root->val) + " " + serialize(root->left) + serialize(root->right);
    }
    
    string serialize2(TreeNode* root, const string& target, bool &b) {
        if (root == nullptr) return "# ";
        string res = to_string(root->val) + " " + serialize2(root->left, target, b) + serialize2(root->right, target, b);
        if (res == target) b = true;
        return res;
    }
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        string tstr = serialize(t);
        bool res = false;
        serialize2(s, tstr, res);
        return res;
    }
};
