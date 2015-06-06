class Solution {
public:
    bool isSymmetric(TreeNode *root) {
        
        queue<TreeNode*> low;
        if(!root)
            return true;
        low.push(root->left);
        low.push(root->right);
        
        while(!low.empty())
        {
            TreeNode *left = low.front();
            low.pop();
            TreeNode *right = low.front();
            low.pop();
            if(!left && !right)
                continue;
            if( (left && !right) || (!left && right) )
                return false;
            if( left->val != right->val )
                return false;
            low.push(left->left);
            low.push(right->right);
            low.push(left->right);
            low.push(right->left);
        }
        return true;
    }
};
