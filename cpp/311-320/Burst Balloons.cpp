class Solution {
    
    int getValue(vector<int>& nums, int i) {
        if(i < 0 || i >= nums.size()) return 1;
        return nums[i];
    }
    
public:
    int maxCoins(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int len = 1; len <= n; len++) {
            for(int start = 0;start <= n-len;start++) {
                int end = start + len - 1;
                for(int i = start; i <= end; i++) {
                    int coins = nums[i] * getValue(nums, start - 1) * getValue(nums, end + 1);
                    coins += i != start ? dp[start][i - 1] : 0;
                    coins += i != end ? dp[i + 1][end] : 0;
                    dp[start][end] = max(dp[start][end], coins);
                }
            }
        }
        return dp[0][n - 1];
    }
};