class Solution {
public:
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        int n = days.size(), k = days[0].size(); // n city , k weeks
        vector<vector<int>> dp(n, vector<int>(k, -1)); // dp[i][j] - max days play if you spent week j in city i;
        
        return dfs(0, 0, dp, flights, days);
    }
    
    int dfs(int city, int week, vector<vector<int>>& dp, const vector<vector<int>>& flights, const vector<vector<int>>& days) {
        int n = days.size(), k = days[0].size(); // n city , k weeks
        if (week >= k) return 0;
        if (dp[city][week] >= 0) return dp[city][week];
        
        int max_days = 0;
        for (int i = 0; i < n; i++) {
            if (flights[city][i] == 1 || city == i) {
                max_days = max(dfs(i, week+1, dp, flights, days) + days[i][week], max_days);
            }
        }
        
        return dp[city][week] = max_days;
    }
};
