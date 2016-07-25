class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> dp(target+1, 0);
        dp[0] = 1;
        
        for(int i = 1;i <= target;i++) {
            for(int k = 0;k < nums.size();k++) {
                if(i - nums[k] >= 0) {
                    dp[i] += dp[i - nums[k]];
                }
            }
        }
        
        return dp[target];
    }
};
