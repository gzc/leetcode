class Solution {
public:
    int strangePrinter(string s) {
        if (s.length() == 1) return 1;
        if (s.empty()) return 0;
        string str = "";
        str += s[0];
        for (int i = 1; i < s.length(); i++) {
            if (s[i] != str.back()) {
                str += s[i];
            }
        }
        
        int n = str.length();
        vector<vector<int>> dp(n, vector<int>(n, 1));
        
        for (int step = 1; step < n; step++) {
            for (int i = 0; i < n - step; i ++) {
                int j = i + step;
                int temp = INT_MAX;
                for (int k = i; k < j; k++) {
                    int v = dp[i][k] + dp[k+1][j];
                    if (str[k] == str[j]) v--;
                    temp = min(temp, v);
                }
                dp[i][j] = temp;
            }
        }
        
        return dp[0][n-1];
    }
};
