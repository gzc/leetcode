class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int base(0);
        int n = nums.size();
        
        for(; k %= n; n -= k)
            for(int i = 0;i < k;i++)
                swap(nums[base++], nums[n-k+base]);
        
    }
};
