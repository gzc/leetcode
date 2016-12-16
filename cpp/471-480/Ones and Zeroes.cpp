class Solution {
    
    pair<int, int> count(const string& str) {
        int x = 0, y = 0;
        for (char ch : str) {
            if (ch == '0') x++;
            else y++;
        }
        return {x, y};
    }
    
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for (const auto& str : strs) {
            auto pairs = count(str);
            for (int i = m; i >= pairs.first; i--) 
                for (int j = n; j >= pairs.second; j--) 
                    dp[i][j] = max(1 + dp[i-pairs.first][j-pairs.second], dp[i][j]);
        }
        
        return dp[m][n];
    }
};
