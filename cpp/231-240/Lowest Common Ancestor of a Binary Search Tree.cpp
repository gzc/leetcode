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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int v1(p->val),v2(q->val);
        while(root)
        {
            int v = root->val;
            if((v > v1 && v > v2)) root = root->left;
            else if(v < v1 && v < v2) root = root->right;
            else return root;
        }
    }
};