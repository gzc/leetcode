class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, 0);
        
        for (int v : nums) {
            vector<int> dp_copy = dp;
            
            for (int i = 0; i < 3; i++) {
                int tmp = v + dp[i];
                int mod = tmp % 3;
                dp_copy[mod] = max(dp_copy[mod], tmp);
            }
            
            dp = dp_copy;
        }
        
        return dp[0];
    }
};
