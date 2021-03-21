class Solution {
    
    const int HEIGHT = 14;
    
    class TreeNode {
    public:
        TreeNode* next[2];
        int cnt;
        TreeNode () {
            next[0] = nullptr;
            next[1] = nullptr;
            cnt = 0;
        };
    };
    
    void insert(TreeNode* root, int num) {
        TreeNode* cur = root;
        for (int j = HEIGHT; j >= 0; j--) {
            int index = ((num >> j) & 1);
            if (cur->next[index] == nullptr)
                cur->next[index] = new TreeNode();
            cur = cur->next[index];
            cur->cnt++;
        }
    }
    
    int GetCount(TreeNode* root, int num, int limit) {
        TreeNode* cur = root;
        int cnt = 0;
        for (int j = HEIGHT; j >= 0; j--) {
            int bit_num = ((num >> j) & 1);
            int bit_limit = ((limit >> j) & 1);
            
            if (bit_limit == 1) {
                // For bit_num branch, its values are all < limit
                if (cur->next[bit_num] != nullptr) {
                    cnt += cur->next[bit_num]->cnt;
                }
                // we try to pick the side so that it XOR bit_num is 1.
                cur = cur->next[1 - bit_num];
            } else {
                // we pick 'bit_num' child so that it does not exceed limit.
                cur = cur->next[bit_num];
            }
            
            if (cur == nullptr) break;
        }
        return cnt;
    }
    
public:
    int countPairs(vector<int>& nums, int low, int high) {
        TreeNode* root = new TreeNode();
        
        int ans = 0;
        for (int num : nums) {
            ans += GetCount(root, num, high + 1) - GetCount(root, num, low);
            insert(root, num);
        }
        
        return ans;
    }
};
