class Solution {
    int lcs(const string& X, const string& Y) {
        int m = X.size();
        int n = Y.size();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (i == 0 || j == 0)
                    dp[i][j] = 0;
                else if (X[i-1] == Y[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
       }
        
       return dp[m][n];
    }
public:
    int minDistance(string word1, string word2) {
        int len = lcs(word1, word2);
        return word1.size() + word2.size() - 2 * len;
    }
};
