class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int>v;
        if(!root) return v;
        stack<TreeNode*> stacks;
        stacks.push(root);
        
        while(!stacks.empty())
        {
            root = stacks.top();
            stacks.pop();
            v.push_back(root->val);
            
            if(root->right)
                stacks.push(root->right);
            if(root->left)
                stacks.push(root->left);
        }
        return v;
    }
};
