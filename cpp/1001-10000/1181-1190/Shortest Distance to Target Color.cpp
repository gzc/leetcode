class Solution {
public:
    vector<int> shortestDistanceColor(vector<int>& colors, vector<vector<int>>& queries) {
        int n = colors.size();
        vector<vector<int>> dp(n, vector<int>(3, INT_MAX));
        
        vector<int> pos(3, -1);
        for (int i = 0; i < colors.size(); i++) {
            int color = colors[i];
            pos[color-1] = i;
            for (int k = 0; k < 3; k++) {
                dp[i][k] = pos[k] >= 0 ? i - pos[k] : INT_MAX;
            }
        }
        
        pos[0] = pos[1] = pos[2] = -1;
        for (int i = colors.size()-1; i >= 0; i--) {
            int color = colors[i];
            pos[color-1] = i;
            for (int k = 0; k < 3; k++) {
                dp[i][k] = min(dp[i][k], pos[k] >= 0 ? pos[k] - i : INT_MAX);
            }
        }
        
        vector<int> ans;
        for (auto& query : queries) {
            int v = dp[query[0]][query[1]-1];
            ans.push_back(v == INT_MAX ? -1 : v);
        }
        return ans;
    }
};
