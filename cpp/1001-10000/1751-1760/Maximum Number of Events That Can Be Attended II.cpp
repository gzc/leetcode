class Solution {
    
public:
    int maxValue(vector<vector<int>>& events, int k) {
        auto cmp = [](const vector<int>& lhs, const vector<int>& rhs) {
            return lhs[1] < rhs[1];
        };
        sort(events.begin(), events.end(), cmp);
        
        int n = events.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
        for (int i = 1; i <= n; i++) {
            int non_overlap_index = 0;
            for (int l = i - 1; l >= 1; l--) {
                if (events[l-1][1] < events[i-1][0]) {
                    non_overlap_index = l;
                    break;
                }
            }
            for (int j = 1; j <= k; j++) {
                dp[i][j] = max(dp[non_overlap_index][j-1] + events[i-1][2], dp[i-1][j]);
            }
        }
        return dp[n][k];
    }
};
