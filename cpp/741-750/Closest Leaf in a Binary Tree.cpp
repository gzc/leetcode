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
    
    vector<int> nodes[1001];
    
    void dfs(TreeNode* root, int k) {
        if (!root) return;
        if (root-> left) {
            nodes[root->val].push_back(root->left->val);
            nodes[root->left->val].push_back(root->val);
            dfs(root->left, k);
        }
        if (root->right) {
            nodes[root->val].push_back(root->right->val);
            nodes[root->right->val].push_back(root->val);
            dfs(root->right, k);   
        }
    }
    
public:
    int findClosestLeaf(TreeNode* root, int k) {
        if (!root->left && !root->right) return root->val;
        dfs (root, k);
        queue<int> myqueue;
        set<int> visited;
        visited.insert(k);
        myqueue.push(k);
        
        while (!myqueue.empty()) {
            int e = myqueue.front();
            myqueue.pop();
            
            if (nodes[e].size() == 1 && e != root->val) return e;
            
            for (int t : nodes[e]) {
                if (visited.count(t) == 0) {
                    myqueue.push(t);
                    visited.insert(t);
                }
            }
            
        }
        
        return -1;
    }
};
