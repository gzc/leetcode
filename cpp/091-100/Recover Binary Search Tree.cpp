class Solution {
public:
    void recoverTree(TreeNode* root) {
        stack<TreeNode*>s;
        TreeNode *p = root;
        TreeNode *prev(nullptr);
        bool fff(false);
        TreeNode *n1(nullptr), *n2(nullptr);
        
        while (p || !s.empty()) {
            while (p) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            if (prev && prev->val > p->val) {
                n2 = p;
                if (!fff){
                    fff = true;
                    n1 = prev;
                } else {
                    swap(n1->val, n2->val);
                    return;
                }
            }
            prev = p;
            p = p->right;
        }
        swap(n1->val, n2->val);
    }
};
