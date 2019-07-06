class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        unordered_map<int, int> dp;
        int ans = 0;
        
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < i; j++) {
                int d = A[i] - A[j];
                int key1 = i * 20001 + d;
                int key2 = j * 20001 + d;
                dp[key1] = max(dp[key1], 1 + dp[key2]);
                ans = max(ans, dp[key1]);
            }
        }
        
        return ans + 1;
    }
};
