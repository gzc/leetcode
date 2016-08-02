class Solution {
    
    TreeNode* flatten(TreeNode* root, TreeNode* pre) {
        if (root == nullptr) return pre;
        pre = flatten(root->right, pre);
        pre = flatten(root->left, pre);
        root->right = pre;
        root->left = nullptr;
        pre = root;
        return root;
    }
    
public:
    void flatten(TreeNode* root) {
        flatten(root, nullptr);
    }
};
