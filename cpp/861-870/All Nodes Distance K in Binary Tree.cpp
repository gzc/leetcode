// Solution 1: O(n) Time, O(n) Space
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
    vector<int> ans;   
    unordered_map<TreeNode*, TreeNode*> parent;  // son=>parent  
    unordered_set<TreeNode*> visit;    //record visied node
    
    void findParent(TreeNode* node) {
        if (node == nullptr) return;
        if (node->left != nullptr) {
            parent[node->left] = node;
            findParent(node->left);
        }
        if (node->right != nullptr){
            parent[node->right] = node;
            findParent(node->right);
        }
    }
    
    void dfs(TreeNode* node, int K){
        if (node == nullptr || visit.count(node) > 0) {
            return;
        }
        visit.insert(node);
        if (K == 0) {
            ans.push_back(node->val);
            return;
        }
        dfs(node->left, K-1);
        dfs(node->right, K-1);
        dfs(parent[node], K-1);
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        findParent(root);
        dfs(target, K);
        return ans;
    }
};

// Solution 2: O(n) Time, O(lgn) Space
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
    bool FindPath(TreeNode* root, TreeNode* target, vector<bool>& paths) {
        if (root == nullptr) {
            return false;
        }
        if (target == root) {
            return true;
        }
        
        bool l = FindPath(root->left, target, paths);
        if (l) {
            paths.push_back(false);
            return true;
        }
        bool r = FindPath(root->right, target, paths);
        if (r) {
            paths.push_back(true);
            return true;
        }
        
        return false;
    }
    
    void FindAnswer(TreeNode* root, vector<int>& ans, int dis, int K) {
        if (root == nullptr || dis > K) {
            return;
        }
        if (dis == K) {
            ans.push_back(root->val);
            return;
        }
        FindAnswer(root->left, ans, dis + 1, K);
        FindAnswer(root->right, ans, dis + 1, K);
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<bool> paths;
        FindPath(root, target, paths);
        reverse(paths.begin(), paths.end());
        
        vector<int> ans;
        for (int i = 0; i < paths.size(); i++) {
            if (paths.size() - i == K) {
                ans.push_back(root->val);
            }
            bool path = paths[i];
            if (path == false) {
                FindAnswer(root->right, ans, paths.size() + 1 - i, K);
                root = root->left;
            } else {
                FindAnswer(root->left, ans, paths.size() + 1 - i, K);
                root = root->right;
            }
        }
        FindAnswer(root, ans, 0, K);
        return ans;
    }
};
