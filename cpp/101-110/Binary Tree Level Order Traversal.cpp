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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        queue<TreeNode*> myqueue({root, nullptr});
        
        vector<int> tmp;
        while (!myqueue.empty()) {
            TreeNode* currentNode = myqueue.front();
            myqueue.pop();
            if (currentNode == nullptr) {
                result.push_back(tmp);
                tmp.clear();
                if (!myqueue.empty()) myqueue.push(nullptr);
            } else {
                tmp.push_back(currentNode->val);
                if (currentNode->left) myqueue.push(currentNode->left);
                if (currentNode->right) myqueue.push(currentNode->right);
            }
        }
        
        return result;
    }
};
