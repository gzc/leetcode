class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1, false);
        dp[0] = false;
        
        vector<int> squares;
        for (int i = 1; i*i <= n; i++) {
            squares.push_back(i*i);
        }
        
        for (int i = 1; i <= n; i++) {
            for (int square : squares) {
                if (i - square < 0) {
                    break;
                }
                
                if (dp[i-square] == false) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
