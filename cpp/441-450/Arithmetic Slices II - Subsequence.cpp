class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        vector<map<int, int>> dp(n);
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            // dp[x][delta] += dp[y][delta] + 1（y∈[0, x - 1]）
            for (int j = 0; j < i; j++) {
                long delta = (long)A[i] - (long)A[j];
                if (delta > INT_MAX || delta < INT_MIN) continue;
                dp[i][delta]++;
                if (dp[j].find(delta) != dp[j].end()) {
                    dp[i][delta] += dp[j][delta];
                    ans += dp[j][delta];
                }
            }
            
        }
        
        return ans;
    }
};
