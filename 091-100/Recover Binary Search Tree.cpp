class Solution {
public:
    void recoverTree(TreeNode* root) {
        
        stack<TreeNode*>s;
        TreeNode *p = root;
        TreeNode *prev(NULL);
        bool fff(false);
        
        TreeNode *n1(NULL),*n2(NULL),*n3(NULL);
        
        while(p || !s.empty())
        {
            while(p)
            {
                s.push(p);
                p = p->left;
            }
                
            p = s.top();
            s.pop();

            if(prev && prev->val > p->val)
            {
                if(!fff){
                    fff = true;
                    n1 = prev;
                    n3 = p;
                } else {
                    n2 = p;
                    swap(n1->val, n2->val);
                    return;
                }
            }
            
            prev = p;
            p = p->right;
        }
        
        if(!n2) swap(n1->val, n3->val);
        
    }
};
