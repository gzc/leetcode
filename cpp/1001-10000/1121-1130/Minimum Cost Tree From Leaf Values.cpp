class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> max_array(n, vector<int>(n, 0));
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        for (int k = 0; k < n; k++) {
            for (int i = 0; i+k < n; i++) {
                int j = i+k;
                if (j >= n) continue;
                if (k == 0) {
                    max_array[i][j] = arr[i];
                    continue;
                }
                if (k==1) {
                    max_array[i][j] = max(arr[i], arr[j]);
                    dp[i][j] += arr[i] * arr[j];
                } else {
                    max_array[i][j] = max(max_array[i][j-1], arr[j]);
                    
                    int temp = INT_MAX;
                    for (int t = i; t < j; t++) {
                        temp = min(temp, dp[i][t] + dp[t+1][j] + max_array[i][t] * max_array[t+1][j]);
                    }
                    dp[i][j] = temp;
                }
            }
        }
        
        return dp[0][n-1];
    }
};
