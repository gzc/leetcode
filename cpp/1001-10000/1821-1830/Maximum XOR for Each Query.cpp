class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int> ans;
        
        int sum = 0;
        for (int num : nums) sum ^= num;
        
        int max_num = 0;
        for (int k = 1; k <= maximumBit; k++) {
            max_num *= 2;
            max_num++;
        }
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans.push_back(max_num ^ sum);
            sum ^= nums[i];
        }
        
        return ans;
    }
};
