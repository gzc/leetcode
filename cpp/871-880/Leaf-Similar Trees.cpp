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
    
    int next(stack<TreeNode*>& mystack) {
        while (true) {
            TreeNode* cur = mystack.top();
            mystack.pop();
            if (cur->right) {
                mystack.push(cur->right);
            }
            if (cur->left) {
                mystack.push(cur->left);
            }
            if (!cur->left && !cur->right) {
                return cur->val;
            }
        }
    }
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*> stackOne;
        stackOne.push(root1);
        stack<TreeNode*> stackTwo;
        stackTwo.push(root2);
        
        while (true) {
            if (stackOne.empty() && stackTwo.empty()) {
                return true;
            }
            if (!stackOne.empty() && !stackTwo.empty()) {
                int v1 = next(stackOne);
                int v2 = next(stackTwo);
                if (v1 != v2) return false;
            } else {
                return false;
            }
        }
    }
};
