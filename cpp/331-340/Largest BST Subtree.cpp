class Solution {
    
    bool isBST(TreeNode* node, int& res, int& mini, int& maxi) {
        
        if (!node)
            return true;
        
        int left_size=0, right_size=0;
        int left_mini, left_maxi, right_mini, right_maxi;
        
        bool leftB = isBST(node->left, left_size, left_mini, left_maxi);
        bool rightB = isBST(node->right, right_size, right_mini, right_maxi);
        
        if (leftB && rightB) {
            if ( (!node->left || node->val >= left_maxi) && (!node->right || node->val <= right_mini) ) {
                /* The tree rooted at this node is a binary search tree */
                res = left_size+right_size+1;
                
                mini = node->left ? left_mini : node->val;
                maxi = node->right ? right_maxi : node->val;
                return true;
            }
        }
        /* The tree rooted at this node is not a binary search tree, so take the maximum size of the BST in the left or right subtrees  */
        res = max(left_size, right_size);
        return false;
    }
    
public:
    int largestBSTSubtree(TreeNode* root) {
        
        int res = 0;
        int mini, maxi;
        bool b = isBST(root, res, mini, maxi);
        
        return res;
    }
    
};