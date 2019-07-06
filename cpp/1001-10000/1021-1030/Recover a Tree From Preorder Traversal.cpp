/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
    TreeNode* dfs(const string& S, int& i, int d) {
        int dash_count = 0;
        int i_ = i;
        while (i_ < S.length() && S[i_] == '-') {
            dash_count++;
            i_++;
        }
        
        if (dash_count != d) return nullptr;
        
        int num = 0;
        
        while (i_ < S.length() && isdigit(S[i_])) {
            num = 10 * num + (S[i_] - '0');
            i_++;
        }
        
        i = i_;
        TreeNode* node = new TreeNode(num);
        node->left = dfs(S, i, d+1);
        node->right = dfs(S, i, d+1);
        
        return node;
    }
    
public:
    TreeNode* recoverFromPreorder(string S) {
        int i = 0;
        return dfs(S, i, 0);
    }
};
