class Solution {
    
public:
    int distinctSubseqII(string S) {
        // Create an array to store index of last 
        vector<int> last(256, -1);
        int n = S.length(); 
        long dp[n+1];
        long MOD = 1000000007;

        // Empty substring has only one subsequence
        dp[0] = 1; 

        for (int i = 1; i <= n; i++) { 
            dp[i] = (2*dp[i-1]) % MOD; 

            // If current character has appeared before, then remove all subsequences 
            // ending with previous occurrence. 
            if (last[S[i-1]] != -1) 
                dp[i] = (dp[i] + MOD - dp[last[S[i-1]]]) % MOD; 
 
            last[S[i-1]] = (i-1);
        } 

        // Remove the empty string.
        return dp[n] - 1; 
    }
};
