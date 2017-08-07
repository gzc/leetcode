class Solution {
public:
    vector<int> cheapestJump(vector<int>& A, int B) {
        vector<int> ans;
        if (A.empty() || A.back() == -1) return ans;
        int n = A.size();
        vector<int> dp(n, INT_MAX), pos(n, -1);
        dp[n-1] = A[n-1];
        // working backward
        for (int i = n-2; i >= 0; i--) {
            if (A[i] == -1) continue;
            for (int j = i+1; j <= min(i+B, n-1); j++) {
                if (dp[j] == INT_MAX) continue;
                if (A[i]+dp[j] < dp[i]) {
                    dp[i] = A[i]+dp[j];
                    pos[i] = j;
                }
            }
        }
        // cannot jump to An
        if (dp[0] == INT_MAX) return ans;
        int k = 0;
        while (k != -1) {
            ans.push_back(k+1);
            k = pos[k];
        }
        return ans;
    }
};
