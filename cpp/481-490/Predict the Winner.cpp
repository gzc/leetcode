class Solution {
    
public:
    bool PredictTheWinner(vector<int>& nums) {
        int sum = accumulate(begin(nums), end(nums), 0);
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) dp[i][i] = nums[i];
        for (int i = 0; i < n-1; i++) dp[i][i+1] = max(nums[i], nums[i+1]);
        for (int k = 2; k < n; k++) {
            for (int i = 0; i+k < n; i++) {
                int v1 = nums[i] + dp[i+2][i+k];
                int v2 = nums[i] + dp[i+1][i+k-1];
                int v3 = nums[i+k] + dp[i][i+k-2];
                int v4 = nums[i+k] + dp[i+1][i+k-1];
                dp[i][i+k] = max(min(v1,v2), min(v3,v4));
            }
        }
        return dp[0][n-1] >= sum - dp[0][n-1];
    }
};
