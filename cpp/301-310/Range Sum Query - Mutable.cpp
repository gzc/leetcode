class SegmentTreeNode {
    
public:
    int start, end, sum;
    SegmentTreeNode *left, *right;
    SegmentTreeNode(int start, int end, int sum) {
        this->start = start;
        this->end = end;
        this->sum = sum;
        this->left = this->right = NULL;
    }
};

class NumArray {
    
    SegmentTreeNode *root;
    
    SegmentTreeNode * build(int start, int end, vector<int>& A) {
        // write your code here
        if(start > end) return nullptr;
        if(start == end) {
            SegmentTreeNode *tree = new SegmentTreeNode(start, end, A[start]);
            return tree;
        }
        if(start < end) {
            SegmentTreeNode *left = build(start, (start+end)/2, A);
            SegmentTreeNode *right = build((start+end)/2+1, end, A);
            SegmentTreeNode *tree = new SegmentTreeNode(start, end, left->sum + right->sum);
            tree -> left = left;
            tree -> right = right;
            return tree;
        }
    }
    
    void modify(SegmentTreeNode *root, int i, int val) {
        if(root->start == root->end) {
            root->sum = val;
            return;
        }
        if(i <= root->left->end) modify(root->left, i, val);
        else modify(root->right, i, val);
        root->sum = root->left->sum + root->right->sum;
    }
    
    int query(SegmentTreeNode *root, int i, int j) {
        if(root->start == root->end) return root->sum;
        if(root->start == i && root->end == j) return root->sum;
        
        if(j <= root->left->end) {
            return query(root->left, i, j);
        } else if(i >= root->right->start) {
            return query(root->right, i, j);
        } else {
            return query(root->left, i, root->left->end) + query(root->right, root->right->start, j);
        }
    }
    
public:
    NumArray(vector<int> &nums) {
        root = build(0, nums.size()-1, nums);
    }
    
    void update(int i, int val) {
        modify(root, i, val);
    }
    
    int sumRange(int i, int j) {
        return query(root, i, j);
    }
};


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.update(1, 10);
// numArray.sumRange(1, 2);