class Solution {
public:
    vector<int> n;
    Solution(vector<int> nums)  {
        n = nums;
    }
    
    int pick(int target) {
        int count = 0, res = -1;
        for (int i = 0; i < n.size(); ++i) {
            if (n[i] != target) continue;
            if (++count == 1) res = i;
            else if (!(rand()%count)) res = i;
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
