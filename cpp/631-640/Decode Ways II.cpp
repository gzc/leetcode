class Solution {
    const int mod = 1000000007;
    
    int ways(char ch) {
        if (ch == '*') return 9;
        if (ch == '0') return 0;
        return 1;
    }
    
    int ways(char ch1, char ch2) {
        if (ch1 == '0') return 0;
        if (ch1 == '*') {
            if (ch2 == '*') return 15;
            if (ch2 <= '6') return 2;
            return 1;
        }
        if (ch1 == '1') {
            if (ch2 == '*') return 9;
            return 1;
        }
        if (ch1 == '2') {
            if (ch2 == '*') return 6;
            if (ch2 <= '6') return 1;
            return 0;
        }
        return 0;
    }
    
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<long> dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                dp[0] = ways(s[0]);
            } else if (i == 1) {
                dp[1] = dp[0] * ways(s[1]) + ways(s[0], s[1]);
            } else {
                dp[i] = (dp[i - 1] * ways(s[i]) + dp[i - 2] * ways(s[i - 1], s[i])) % mod;
            }
        }
        return dp[n - 1];
    }
};
