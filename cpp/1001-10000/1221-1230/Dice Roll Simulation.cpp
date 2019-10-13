class Solution {
public:
    int dieSimulator(int n, vector<int>& rollMax) {
        long cnt = 0;
        long MOD = 1e9+7;
        vector<vector<long>> dp(7, vector<long>(16, 0));
        dp[1][1] = dp[2][1] = dp[3][1] = dp[4][1] = dp[5][1] = dp[6][1] = 1;
        for (int k = 2; k <= n; k++) {
            vector<vector<long>> dp_tmp(7, vector<long>(16, 0));
            // 这一层循环，是骰子有6种可能性
            for (int i = 1; i <= 6; i++) {
                // 这一层循环，是前一次骰子有6种可能性
                for (int j = 1; j <= 6; j++) {
                    // 这一层循环，是前一次骰子在最后重复的次数
                    for (int m = 1; m < 16; m++) {
                        long v = dp[j][m];
                        if (i == j) {
                            if (m+1 <= rollMax[i-1]) {
                                dp_tmp[i][m+1] = (dp_tmp[i][m+1] + v) % MOD;
                            }
                        } else {
                            dp_tmp[i][1] = (dp_tmp[i][1] + v) % MOD;
                        }
                    }
                }
            }
            
            swap(dp, dp_tmp);
        }
        
        for (int i = 1; i <= 6; i++) {
            for (int j = 1; j <= 15; j++) {
                cnt = (cnt + dp[i][j]) % MOD;
            }
        }
        return cnt;
    }
};
