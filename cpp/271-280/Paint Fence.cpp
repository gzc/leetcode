class Solution {
public:
    int numWays(int n, int k) {
        vector<vector<int>> dp(2, vector<int>(n+2, 0));
        dp[0][0] = 0;
        dp[0][1] = k;
        dp[1][0] = k;
        dp[1][1] = k*(k-1);
        
        for (int i = 2; i < n; i++) {
            dp[0][i] = dp[1][i-1];
            dp[1][i] = (k-1) * (dp[0][i-1] + dp[1][i-1]);
        }
        
        return dp[0][n-1] + dp[1][n-1];
    }
};
