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
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        
        stack<TreeNode*> s;
        s.push(root);
        bool flag(false);
        
        while(!s.empty() || root)
        {
            while(root && root->left)
            {
                s.push(root->left);
                root = root->left;
            }
            
            root = s.top();
            s.pop();
            if(flag) return root;
            if(root == p) flag = true;
            
            if(root->right)
                s.push(root->right);
            root = root->right;
        }
        
        return nullptr;
    }
};