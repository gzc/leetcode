class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> dp(K+1, vector<vector<double>>(N, vector<double>(N, -1.0)));
        return helper(dp, N, K, r, c)/pow(8, K);
    }
private:
    double helper(vector<vector<vector<double>>>& dp, int N, int k, int r, int c) {
        // if out of board, return 0.0
        if (r < 0 || r >= N || c < 0 || c >= N) return 0.0;
        // when k = 0, no more move, so it's 100% safe
        if (k == 0) return 1.0;
        if (dp[k][r][c] > -0.000001) return dp[k][r][c];
        dp[k][r][c] = 0.0;
        for (int i = -2; i <= 2; i++) {
            if (i == 0) continue;
            dp[k][r][c] += helper(dp, N, k-1, r+i, c+3-abs(i)) + helper(dp, N, k-1, r+i, c-(3-abs(i)));
        }      
        return dp[k][r][c];
    }
};
