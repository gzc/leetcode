class Solution {
    
    bool inBox(int i, int j, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n) return false;
        return true;
    }
    
    long get(int i, int j, int k, vector<vector<vector<long>>>& dp, int m, int n) {
        if (!inBox(j, k, m, n)) return 0;
        return dp[i][j][k];
    }
    
    int coeff(int i, int j, int m, int n) {
        int coe = 0;
        if (!inBox(i, j - 1, m, n)) coe++;
        if (!inBox(i, j + 1, m, n)) coe++;
        if (!inBox(i - 1, j, m, n)) coe++;
        if (!inBox(i + 1, j, m, n)) coe++;
        return coe;
    }
    
public:
    int findPaths(int m, int n, int N, int i, int j) {
        if (N == 0) return 0;
        vector<vector<vector<long>>> dp(N + 1, vector<vector<long>>(m, vector<long>(n, 0)));
        dp[0][i][j] = 1;
        long result = 1 * coeff(i, j, m, n);
        for (int i = 1; i < N; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < n; k++) {
                    dp[i][j][k] = (get(i - 1, j - 1, k, dp , m, n)
                        + get(i - 1, j + 1, k, dp , m, n)
                        + get(i - 1, j, k - 1, dp , m, n)
                        + get(i - 1, j, k + 1, dp , m, n)) % 1000000007;
                    result += coeff(j, k, m, n) * dp[i][j][k];
                    result %= 1000000007;
                }
            } 
        }

        return result;
    }
};
