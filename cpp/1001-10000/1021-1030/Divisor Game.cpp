class Solution {
    map<int, bool> dp;
public:
    bool divisorGame(int N) {
        if (N == 0) return false;
        if (dp.count(N) > 0) return dp[N];
        for (int i = 1; i < N; i++) {
            if (N % i == 0) {
                bool win = !divisorGame(N - i);
                if (win) {
                    return dp[N] = win;
                }
            }
        }
        
        return dp[N] = false;
    }
};
