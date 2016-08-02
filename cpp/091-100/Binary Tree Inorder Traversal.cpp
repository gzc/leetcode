class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> node_in_path;
        TreeNode* current_node = root;
        
        while (current_node || !node_in_path.empty())
        {
            while (current_node)
            {
                node_in_path.emplace(current_node);
                current_node = current_node->left;
            }
                
            current_node = node_in_path.top();
            node_in_path.pop();
            result.push_back(current_node->val);
            current_node = current_node->right;
        }
        
        return result;
    }
};
