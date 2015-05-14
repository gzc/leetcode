class Solution {
    
    TreeNode *help(vector<int>::iterator first, vector<int>::iterator last, vector<int>::iterator pfirst, vector<int>::iterator plast)
    {
        int mid = *pfirst;
        TreeNode *node = new TreeNode(mid);
        
        if(first == last)
            return node;
        
        vector<int>::iterator inorder_min = find(first, last, mid);
        vector<int>::iterator porder_break;
        TreeNode *left,*right;
        if(inorder_min == first)
        {
            left = NULL;
            right = help(first+1, last, pfirst+1, plast);
        } else if(inorder_min == last)
        {
            right = NULL;
            left = help(first,last-1,pfirst+1,plast);
        } else
        {
            int diff = inorder_min-first;
            left = help(first, inorder_min-1, pfirst+1, pfirst+diff);
            right = help(inorder_min+1, last, pfirst+diff+1,plast);
        }

        node->left = left;
        node->right = right;
        return node;
    }
    
public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if(inorder.size() == 0)
            return NULL;
        return help(inorder.begin(), inorder.end()-1, preorder.begin(), preorder.end()-1);
    }
};
