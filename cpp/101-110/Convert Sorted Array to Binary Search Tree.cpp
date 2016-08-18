class Solution {
    
    TreeNode *help(vector<int>::iterator it1, vector<int>::iterator it2) {
        if (it1 == it2)
            return new TreeNode(*it1);
        if (it1 > it2)
            return nullptr;
        vector<int>::iterator midit = it1+(it2-it1)/2;
        TreeNode *node = new TreeNode(*midit);
        node->left = help(it1,midit-1);
        node->right = help(midit+1, it2);
        return node;
    }
    
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.size() == 0)
            return nullptr;
        return help(num.begin(), num.end()-1);
    }
};
