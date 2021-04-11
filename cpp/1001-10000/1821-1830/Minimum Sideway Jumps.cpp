class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size();
        vector<vector<int>> dp (n, vector<int>(3, 99999999));
        dp[0][1] = 0;
        dp[0][0] = dp[0][2] = 1;
        
        for (int i = 1; i < n; i++) {
            for (int k = 0; k < 3; k++) {
                if (obstacles[i - 1] == (k + 1) || obstacles[i] == (k + 1)) {
                    dp[i][k] = 99999999;
                } else {
                    int a_lane = (k + 1) % 3;
                    int b_lane = (k + 2) % 3;
                    dp[i][k] = min(dp[i - 1][k], min(dp[i - 1][a_lane], dp[i - 1][b_lane]) + 1);
                }
            }
        }
        
        return min(dp[n-1][0], min(dp[n-1][1], dp[n-1][2]));
    }
};
