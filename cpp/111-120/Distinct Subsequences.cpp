class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n+1, vector<int>(m + 1, 0));
        
        for(int k = 0; k <= n; k++)
            dp[k][0] = 1;
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j];
                if(s[i-1] == t[j-1])
                    dp[i][j] += dp[i-1][j-1];
            }
        }
        
        return dp[n][m];
    }
};
