class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        
        vector<int>v;
        if(!root) return v;
        stack<TreeNode*> stacks;
        stacks.push(root);
        
        while(!stacks.empty())
        {
            root = stacks.top();
            stacks.pop();
            v.push_back(root->val);
            
            if(root->left)
                stacks.push(root->left);
            if(root->right)
                stacks.push(root->right);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};
