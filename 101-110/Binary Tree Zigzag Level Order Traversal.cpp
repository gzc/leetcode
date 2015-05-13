class Solution {
    
    void help(TreeNode *root, int level, vector<vector<int>>& results)
    {
        if(root)
        {
            if(results.size() == level)
            {
                vector<int> v;
                results.push_back(v);
            }
            results[level].push_back(root->val);
            help(root->left, level+1, results);
            help(root->right, level+1, results);
        }
    }
    
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> results;
        
        help(root, 0, results);
        
        for(int i = 0;i < results.size();i++)
            if(i % 2 == 1)
                reverse(results[i].begin(), results[i].end());
        
        return results;
    }
};
