#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode *root) {
        vector<int> r;
        if(root == NULL) return r;
        
        vector<TreeNode*>node;
        node.push_back(root);
        
        while(node.size() > 0)
        {
            r.push_back(node.back()->val);
            
            size_t len = node.size();
            for(int i = 0;i < len;i++)
            {
                if(node[i]->left)node.push_back(node[i]->left);
                if(node[i]->right)node.push_back(node[i]->right);
            }
            
            node.erase(node.begin(), node.begin()+len);
        }
        
        return r;
    }
    
};

int main()
{
    Solution s;
    
    struct TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left->right = new TreeNode(8);
    
    cout << s.rightSideView(root).size();
    return 0;
}