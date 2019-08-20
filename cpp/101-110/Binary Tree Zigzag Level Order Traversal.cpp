class Solution {
    
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        
        bool flag = true;
        
        while (!myqueue.empty()) {
            int size_ = myqueue.size();
            vector<int> n_vec(size_, 0);
            
            for (int i = 0; i < size_; i++) {
                TreeNode* ele = myqueue.front();
                myqueue.pop();
                if (flag) n_vec[i] = ele->val;
                else n_vec[size_ - i - 1] = ele->val;
                
                if (ele->left) {
                    myqueue.push(ele->left);
                }
                if (ele->right) {
                    myqueue.push(ele->right);
                }
            }
            
            flag = !flag;
            
            result.emplace_back(n_vec);
        }
        
        return result;
    }
};
