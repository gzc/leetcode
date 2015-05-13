class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> v;
        stack<TreeNode*>s;
        TreeNode *p = root;
        
        while(p || !s.empty())
        {
            while(p)
            {
                s.push(p);
                p = p->left;
            }
                
            p = s.top();
            s.pop();
            v.push_back(p->val);
            p = p->right;
        }
        
        return v;
    }
};
