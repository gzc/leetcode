class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (root == nullptr) return result;
        stack<TreeNode*> nodes_ready_for_visiting;
        nodes_ready_for_visiting.emplace(root);
        
        while (!nodes_ready_for_visiting.empty())
        {
            root = nodes_ready_for_visiting.top();
            nodes_ready_for_visiting.pop();
            result.emplace(result.end(), root->val);
            
            if (root->left)
                nodes_ready_for_visiting.emplace(root->left);
            if (root->right)
                nodes_ready_for_visiting.emplace(root->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
