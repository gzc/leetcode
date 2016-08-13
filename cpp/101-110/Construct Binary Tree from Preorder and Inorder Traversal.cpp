class Solution {

TreeNode* helper(vector<int>& preorder,int i,int j,vector<int>& inorder,int ii,int jj) {
        if(i >= j) return nullptr;
        int mid = preorder[i];
        auto f = find(inorder.begin() + ii,inorder.begin() + jj,mid);
        int dis = f - inorder.begin() - ii;
        TreeNode* root = new TreeNode(mid);
        root -> left = helper(preorder,i + 1,i + 1 + dis,inorder,ii,ii + dis);
        root -> right = helper(preorder,i + 1 + dis,j,inorder,ii + dis + 1,jj);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder,0,preorder.size(),inorder,0,inorder.size());
    }
};
