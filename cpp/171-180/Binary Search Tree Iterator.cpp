class BSTIterator {
    
    stack<TreeNode *> s;
    
public:
    BSTIterator(TreeNode *root) {
        
        while(root)
        {
            s.push(root);
            root = root->left;
        }
        
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *cur = s.top();
        s.pop();
        int val = cur->val;
        
        if(cur->right)
        {
            cur = cur->right;
            while(cur)
            {
                s.push(cur);
                cur = cur->left;
            }
        }
        
        return val;
    }
};
