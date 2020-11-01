class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int m = destination[0]+1;
        int n = destination[1]+1;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[m-1][n-1] = 1;
        
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (i != m -1) dp[i][j] += dp[i+1][j];
                if (j != n - 1) dp[i][j] += dp[i][j+1];
            }
        }
        
        string ans;
        int i = 0; int j = 0;
        while ( !(i == m-1 && j == n-1) ) {
            if (i == m-1) { ans += 'H'; j++; continue; }
            else if (j == n-1) { ans += 'V'; i++; continue; }
            
            int h = dp[i][j+1];
            int v = dp[i+1][j];
            if (k <= h) {
                ans += 'H'; j++;
            } else {
                k -= h;
                ans += 'V'; i++;
            }
        }
        
        return ans;
    }
};
