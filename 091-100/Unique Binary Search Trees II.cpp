class Solution {
    
    vector<TreeNode *> generate(int beg, int end)
    {
        vector<TreeNode* > ret;
        if (beg > end)
        {
            ret.push_back(NULL);
            return ret;
        }
        
        for(int i = beg; i <= end; i++)
        {
            vector<TreeNode* > leftTree = generate(beg, i - 1);
            vector<TreeNode* > rightTree = generate(i + 1, end);
            for(int j = 0; j < leftTree.size(); j++)
                for(int k = 0; k < rightTree.size(); k++)
                {
                    TreeNode *node = new TreeNode(i + 1);
                    ret.push_back(node);
                    node->left = leftTree[j];
                    node->right = rightTree[k];              
                }           
        }
        
        return ret;
    }

public:

    vector<TreeNode *> generateTrees(int n) {
        return generate(0, n - 1);
    }
};
