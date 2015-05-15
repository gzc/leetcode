class Solution {
    
public:
    void flatten(TreeNode *root) {
        while ( root ) {
            if ( root->left ) {
                TreeNode *ptr = root->left;
                while ( ptr->right ) ptr = ptr->right;
                ptr->right = root->right;
                root->right = root->left;
                root->left = NULL;
            }
            root = root->right;
        }
    }
};
