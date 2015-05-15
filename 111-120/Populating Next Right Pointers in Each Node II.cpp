class Solution {
public:
    void connect(TreeLinkNode *root) {
        
        TreeLinkNode *ancestor = root;
        while(ancestor)
        {
            TreeLinkNode *tln = ancestor;
            TreeLinkNode *prev(NULL);
            
            while(tln)
            {
                
                if(tln->left)
                {
                    if(!prev)
                    {
                        prev = tln->left;
                        ancestor = prev;
                    }
                    else
                    {
                        prev->next = tln->left;
                        prev = prev->next;
                    }
                }
                
                if(tln->right)
                {
                    if(!prev)
                    {
                        prev = tln->right;
                        ancestor = prev;
                    }
                    else
                    {
                        prev->next = tln->right;
                        prev = prev->next;
                    }
                }
                
                tln = tln->next;
            }
            if(!prev) return;
        }
        
    }
};
