class Solution {
    const int mod = pow(10, 9) + 7;
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
        return dfs(n, k, dp);
    }
    
    long dfs(int n, int k, vector<vector<int>>& dp) {
        if (n == 0) return 0;
        if (n == 1 && k == 0) return 1;
        if (n == 1 && k == 1) return 0;
        if (k == 0) return 1;
        if (n == 2 && k == 1) return 1;
        int bound = (n-1)*n/2;
        if (k > bound) return 0;
        if (dp[n][k] > -1) return dp[n][k];
        int temp = 0;
        if (k > bound/2) return dp[n][k] = ( dfs(n, bound - k, dp) % mod);
        else temp = (dfs(n - 1, k, dp) + dfs(n, k - 1, dp)) % mod;
        int nonused = k - n;
        if (nonused >= 0) temp = (temp + mod - dfs(n - 1, nonused, dp)) % mod;
        return dp[n][k] = temp;
    }

};
