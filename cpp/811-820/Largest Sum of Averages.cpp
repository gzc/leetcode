class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<vector<double>> dp(n+1, vector<double>(K+1, 0));
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= K; j++) {
                int temp = 0;
                for (int v = i - 1; v >= 0; v--) {
                    temp += A[v];
                    int numElement = i - v;
                    if (i - numElement < j - 1 || (i - numElement > 0 && j - 1 <= 0)) continue;
                    dp[i][j] = max(dp[i][j], dp[i - numElement][j-1] + 1.0*temp/numElement);
                }
            }
        }
        
        return dp[n][K];
    }
};
