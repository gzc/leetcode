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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        map<int, vector<int>> mymap;
        vector<vector<int>> res;
        
        if(!root) return res;
        
        queue<TreeNode*> nodequeue;
        queue<int>idqueue;
        nodequeue.push(root);
        idqueue.push(0);
        
        while(!nodequeue.empty()) {
            TreeNode* cur = nodequeue.front();
            int id = idqueue.front();
            nodequeue.pop();
            idqueue.pop();
            
            if(mymap.count(id) == 0) {
                vector<int> temp;
                mymap[id] = temp;
            }
            mymap[id].push_back(cur->val);
            
            if(cur -> left) {
                nodequeue.push(cur->left);
                idqueue.push(id-1);
            }
            if(cur -> right) {
                nodequeue.push(cur->right);
                idqueue.push(id+1);
            }
        }
        
        for(auto e : mymap)
            res.push_back(e.second);
        return res;
    }
};