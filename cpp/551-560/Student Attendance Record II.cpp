class Solution {
    
    int MOD = 1000000007;
    
    long sum(long nums[]) {
        return (nums[0]+nums[1]+nums[2]) % MOD;
    }
public:
    int checkRecord(int n) {
        // dp[n][A][L], 长度为n，包含A个字符'A'，以L个连续的'L'结尾的字符串的个数
        long dp[2][3] = {{1, 1, 0}, {1, 0, 0}};
        for (int i = 2; i <= n; i++) {
            long ndp[2][3] = {{0, 0, 0}, {0, 0, 0}};
            ndp[0][0] = sum(dp[0]);
            ndp[0][1] = dp[0][0];
            ndp[0][2] = dp[0][1];
            ndp[1][0] = (sum(dp[0]) + sum(dp[1])) % MOD;
            ndp[1][1] = dp[1][0];
            ndp[1][2] = dp[1][1];
            memcpy(dp, ndp, 6*sizeof(long));
        }
        return (int)((sum(dp[0]) + sum(dp[1])) % MOD);
    }
};
