class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        if (M.size() == 0)
            return 0;
        int ones = 0;
        vector<vector<vector<int>>> dp = vector<vector<vector<int>>>(M.size(), vector<vector<int>>(M[0].size(), vector<int>(4,0)));
        for (int i = 0; i < M.size(); i++) {
            for (int j = 0; j < M[0].size(); j++) {
                if (M[i][j] == 1) {
                    dp[i][j][0] = j > 0 ? dp[i][j - 1][0] + 1 : 1;
                    dp[i][j][1] = i > 0 ? dp[i - 1][j][1] + 1 : 1;
                    dp[i][j][2] = (i > 0 && j > 0) ? dp[i - 1][j - 1][2] + 1 : 1;
                    dp[i][j][3] = (i > 0 && j < M[0].size() - 1) ? dp[i - 1][j + 1][3]+1 : 1;
                    ones = max(ones, max(max(dp[i][j][0], dp[i][j][1]), max(dp[i][j][2], dp[i][j][3])));
                }
            }
        }
        return ones;
    }
};
