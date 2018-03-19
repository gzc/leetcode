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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> counts;
        int maxCount = 0;
        countSubtreeSums(root, counts, maxCount);
        
        vector<int> maxSums;
        for(const auto& x :  counts){
            if(x.second == maxCount) maxSums.push_back(x.first);
        }
        return maxSums;
    }
    
    int countSubtreeSums(TreeNode *r, unordered_map<int,int> &counts, int& maxCount){
        if(r == nullptr) return 0;
        
        int sum = r->val;
        sum += countSubtreeSums(r->left, counts, maxCount);
        sum += countSubtreeSums(r->right, counts, maxCount);
        ++counts[sum];
        maxCount = max(maxCount, counts[sum]);
        return sum;
    }
};
