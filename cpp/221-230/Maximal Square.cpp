class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix.front().empty()) return 0;
        int m = matrix.size();
        int n = matrix.front().size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int maxLen = 0;
        
        for (int i = 0; i < m; i++) {
            for (int j = 0;j < n; j++) {
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1;
                    if (i > 0 && j > 0) {
                        int tmp = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
                        dp[i][j] = max(dp[i][j], tmp+1);
                    }
                }
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        
        return maxLen*maxLen;
    }
};
