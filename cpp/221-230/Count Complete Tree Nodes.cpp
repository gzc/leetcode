class Solution {
    
public:
    int countNodes(TreeNode* root) {
        
        if(!root) return 0;
        
        int lh(0),rh(0);
        
        TreeNode *l(root), *r(root);
        
        while(l) {
            lh++;
            l = l->left;
        }
        
        while(r) {
            rh++;
            r = r->right;
        }
        
        if(lh == rh) return pow(2, lh) - 1;
        else return 1 + countNodes(root->left) + countNodes(root->right);
    }
};