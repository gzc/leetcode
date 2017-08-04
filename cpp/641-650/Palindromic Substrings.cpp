class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        vector<vector<bool>> dp(s.length(), vector<bool>(s.length(), false));
        for (int i = 0; i < s.length(); i++) {
            dp[i][i] = true;
            res++;
        }
        
        for (int i = 0; i < s.length() - 1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                res++;
            }
        }
        
        for (int step = 2; step < s.length(); step++) {
            for (int i = 0; i < s.length() - step; i++) {
                int j = i + step;
                if (s[i] == s[j] && dp[i+1][j-1]) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
        
        return res;
    }
};
