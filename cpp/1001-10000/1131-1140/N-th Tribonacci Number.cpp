class Solution {
public:
    int tribonacci(int n) {
        int dp[50] = {0};
        dp[1] = 1;
        dp[2] = 1;
        if (n <= 2) return dp[n];
        
        for (int i = 3; i <= n; i++) {
            dp[i] = dp[i-3] + dp[i-2] + dp[i-1];
        }
        
        return dp[n];
    }
};
