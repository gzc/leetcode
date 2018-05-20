/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        while (root) {
            TreeLinkNode *tln = root;
            TreeLinkNode *prev = new TreeLinkNode(0);
            TreeLinkNode *temp = prev;
            
            while (tln) {
                
                if (tln->left) {
                    prev->next = tln->left;
                    prev = prev->next;
                }
                
                if(tln->right) {
                    prev->next = tln->right;
                    prev = prev->next;
                }
                
                tln = tln->next;
            }
            
            root = temp -> next;
        }
    }
};
