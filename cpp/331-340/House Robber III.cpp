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
    
    void help(TreeNode* root, int &a, int &b) {
        if(root == nullptr) {
            a = 0;
            b = 0;
            return;
        }
        
        int a1,a2,b1,b2;
        help(root->left, a1, b1);
        help(root->right, a2, b2);
        
        a = root->val + b1 + b2;
        b = max(a1 + a2, a1 + b2);
        b = max(b, a2 + b1);
        b = max(b, b1 + b2);
        return;
    }
    
public:
    int rob(TreeNode* root) {
        
        if(!root) return 0;
        int a,b;
        help(root, a, b);
        return max(a,b);
    }
};

/*
 4
 1
 2
 3
 
 
 */