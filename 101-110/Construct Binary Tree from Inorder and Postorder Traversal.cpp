class Solution {
    
    TreeNode *help(vector<int>::iterator first, vector<int>::iterator last, vector<int>::iterator pfirst, vector<int>::iterator plast)
    {
        int mid = *plast;
        TreeNode *node = new TreeNode(mid);
        
        if(first == last)
            return node;
        
        vector<int>::iterator inorder_min = find(first, last, mid);
        vector<int>::iterator porder_break;
        TreeNode *left,*right;
        if(inorder_min == first)
        {
            left = NULL;
            right = help(first+1, last, pfirst, plast-1);
        } else if(inorder_min == last)
        {
            right = NULL;
            left = help(first,last-1,pfirst,plast-1);
        } else
        {
            int diff = inorder_min-first;
            left = help(first, inorder_min-1, pfirst, pfirst+diff-1);
            right = help(inorder_min+1, last, pfirst+diff,plast-1);
        }

        node->left = left;
        node->right = right;
        return node;
    }
    
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if(inorder.size() == 0)
            return NULL;
        return help(inorder.begin(), inorder.end()-1, postorder.begin(), postorder.end()-1);
    }
};
