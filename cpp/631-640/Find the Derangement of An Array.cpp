class Solution {
    const int mod = 1000000007;
public:
    int findDerangement(int n) {
        vector<long> dp(n, 0);
        bool flag = true;
        for (int i = 2; i <= n; i++) {
            if (flag) {
                dp[i - 1] = (dp[i - 2] * i + 1) % mod;
                flag = false;
            } else {
                dp[i - 1] = (dp[i - 2] * i - 1) % mod;
                flag = true;
            }
        }
        return dp[n - 1];
    }
};
