class Solution {
public:
    void connect(TreeLinkNode *root) {

        TreeLinkNode *ancestor = root;
        while(ancestor)
        {
            TreeLinkNode *tln = ancestor;
            if(!tln->left) break;
            while(tln)
            {
                tln->left->next = tln->right;
                if(tln->next) tln->right->next = tln->next->left;
                tln = tln->next;
            }
            ancestor = ancestor->left;
        }
    }
};
