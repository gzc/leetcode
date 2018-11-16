class Solution {
public:
    int knightDialer(int N) {
        vector<vector<long>> dp(2, vector<long>(10, 1));
        long MOD = 1000000007;
        for (int i = 1; i < N; i++) {
            dp[1][0] = (dp[0][4] + dp[0][6]) % MOD;
            dp[1][1] = (dp[0][6] + dp[0][8]) % MOD;
            dp[1][2] = (dp[0][7] + dp[0][9]) % MOD;
            dp[1][3] = (dp[0][4] + dp[0][8]) % MOD;
            dp[1][4] = (dp[0][0] + dp[0][3] + dp[0][9]) % MOD;
            dp[1][5] = 0;
            dp[1][6] = (dp[0][0] + dp[0][1] + dp[0][7]) % MOD;
            dp[1][7] = (dp[0][2] + dp[0][6]) % MOD;
            dp[1][8] = (dp[0][1] + dp[0][3]) % MOD;
            dp[1][9] = (dp[0][2] + dp[0][4]) % MOD;
            dp[0] = dp[1];
        }
        
        return accumulate(dp.front().begin(), dp.front().end(), 0l) % MOD;
    }
};
