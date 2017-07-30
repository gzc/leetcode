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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> result;
        map<size_t, vector<TreeNode*>> mymap;
        merkle(root, mymap);
        for (const auto& ele : mymap) {
            if (ele.second.size() > 1) {
                result.push_back(ele.second[0]);
            }
        }
        return result;
    }
    
    string merkle(TreeNode* root, map<size_t, vector<TreeNode*>>& mymap) {
        if (root == nullptr) {
            return "#";
        }
        string left = merkle(root->left, mymap);
        string right = merkle(root->right, mymap);
        size_t current = hash<string>{}(left + to_string(root->val) + right);
        mymap[current].push_back(root);
        return to_string(current);
    }
};
