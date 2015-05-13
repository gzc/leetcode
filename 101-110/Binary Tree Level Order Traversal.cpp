class Solution {
    
    void help(TreeNode *root, int level, vector<vector<int>>& results)
    {
        if(root)
        {
            if(results.size() == level)
            {
                vector<int> v;
                v.push_back(root->val);
                results.push_back(v);
            } else {
                results[level].push_back(root->val);
            }
            help(root->left, level+1, results);
            help(root->right, level+1, results);
        }
    }
    
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int>> results;
        
        help(root, 0, results);
        
        return results;
    }
};
