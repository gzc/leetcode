class Solution {
    
    void help(TreeNode *root, int sum, vector<int>& tmp, vector<vector<int>>& r)
    {
        if(!root) return;

        if(!root->left && !root->right && (sum == root->val))
        {
            tmp.push_back(root->val);
            r.push_back(tmp);
            tmp.pop_back();
            return;
        }

        if(root->left)
        {
            tmp.push_back(root->val);
            help(root->left,sum - root->val,tmp,r);
            tmp.pop_back();
        }
        if(root->right)
        {
            tmp.push_back(root->val);
            help(root->right,sum - root->val,tmp,r);
            tmp.pop_back();
        }
    }
    
public:
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> tmp;
        vector<vector<int>>v;
        
        help(root, sum, tmp, v);
        
        return v;
    }
};
