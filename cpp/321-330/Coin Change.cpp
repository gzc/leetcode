class Solution {
    
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        int *dp = new int[amount+1];
        for(int i = 1;i <= amount;i++) dp[i] = -1;
        dp[0] = 0;
        
        for(int i = 1;i <= amount;i++) {
            for(int e : coins) {
                if(i - e < 0 || dp[i-e] < 0) continue;
                int v = dp[i-e] + 1;
                if(dp[i] <= 0) dp[i] = v;
                else dp[i] = min(v, dp[i]);
            }
        }
        
        return dp[amount] <= 0 ? -1 : dp[amount];
    }
};