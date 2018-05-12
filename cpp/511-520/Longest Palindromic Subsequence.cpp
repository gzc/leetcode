class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int step = 0; step < n; step++) {
            for (int i = 0; i + step < n; i++) {
                int j = i + step;
                if (i == j) dp[i][j] = 1;
                else if (i+1 == j) dp[i][j] = ( s[i] == s[j] ? 2 : 1);
                else {
                    if (s[i] == s[j]) {
                        dp[i][j] = 2 + dp[i+1][j-1];
                    } else {
                        dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                    }
                }
            }
        }
        
        return dp[0][n-1];
    }
};
