struct tree{
    int val;
    tree* left;
    tree* right;
    int count;
    tree(int v):val(v),left(nullptr),right(nullptr),count(1){}
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        tree* root(nullptr);
        vector<int> res(nums.size(), 0);
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (root == nullptr) {
                root = new tree(nums[i]);
            } else {
                int temp(0);
                tree* cur = root;
                while (cur != nullptr) {
                    if (nums[i] <= cur->val) {
                        cur->count++;
                        if(cur -> left == nullptr) {
                            tree* node = new tree(nums[i]);
                            cur->left = node;
                            break;
                        }
                        cur = cur->left;
                    } else {
                        temp += cur->count;
                        if (cur -> right == nullptr) {
                            tree* node = new tree(nums[i]);
                            cur->right = node;
                            break;
                        }
                        cur = cur->right;
                    }
                }
                res[i] = temp;
            }
        }
        return res;
    }
};
