class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*>s;
        TreeNode *p = root;
        int prev(INT_MIN);
        bool first(true);
        
        while (p!= nullptr || !s.empty()) {
            while (p != nullptr) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            if (first) {
                prev = p->val;
                first = false;
            } else if (p->val <= prev) {
                return false;
            }
            prev = p->val;
            p = p->right;
        }
        return true;
    }
};
