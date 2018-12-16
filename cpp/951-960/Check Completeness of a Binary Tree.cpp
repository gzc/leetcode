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
public:
    bool isCompleteTree(TreeNode* root) {
        if (root == nullptr) return true;
        queue<TreeNode*> myqueue;
        myqueue.push(root);
        
        bool flag = false;
        
        while (!myqueue.empty()) {
            TreeNode* node = myqueue.front();
            myqueue.pop();
            if (node->left) {
                if (flag) return false;
                myqueue.push(node->left);
            } else {
                flag = true;
            }
            
            if (node->right) {
                if (flag) return false;
                myqueue.push(node->right);
            } else {
                flag = true;
            }
        }
        
        return true;
    }
};
