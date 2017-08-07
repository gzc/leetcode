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
    
    TreeNode* dfs(std::vector<int>::iterator start, std::vector<int>::iterator end) {
        if (start > end) {
            return nullptr;
        }
        if (start == end) {
            return new TreeNode(*start);
        }
        
        std::vector<int>::iterator result;
        result = std::max_element(start, end+1);
        TreeNode* temp = new TreeNode(*result);
        temp->left = dfs(start, result-1);
        temp->right = dfs(result+1, end);
        return temp;
    }
    
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (nums.size() == 0) return nullptr;
        return dfs(nums.begin(), --nums.end());
    }
};
