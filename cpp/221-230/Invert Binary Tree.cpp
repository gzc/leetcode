class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        
        if(!root) return nullptr;
        
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};
