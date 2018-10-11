/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
    TreeNode* myroot;
    queue<TreeNode*> myqueue;
public:
    CBTInserter(TreeNode* root) {
        myroot = root;
        myqueue.push(root);
        while (true) {
            if (myqueue.front()->left && myqueue.front()->right) {
                myqueue.push(myqueue.front()->left);
                myqueue.push(myqueue.front()->right);
                myqueue.pop();
            } else {
                break;
            }
        }
    }
    
    int insert(int v) {
        TreeNode* cur = new TreeNode(v);
        int retVal = myqueue.front()->val;
        if (myqueue.front()->left == nullptr) {
            myqueue.front()->left = cur;
        } else {
            myqueue.front()->right = cur;
            myqueue.push(myqueue.front()->left);
            myqueue.push(cur);
            myqueue.pop();
        }
        return retVal;
    }
    
    TreeNode* get_root() {
        return myroot;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter obj = new CBTInserter(root);
 * int param_1 = obj.insert(v);
 * TreeNode* param_2 = obj.get_root();
 */
