class Solution {

public:
    int findLength(vector<int>& A, vector<int>& B) {
        int maxlen = 0;
        vector<vector<int>>dp (A.size(), vector<int>(B.size(), 0));
        for(int i = 0; i < A.size(); ++i) {
            for(int j = 0; j < B.size(); ++j) {
                if(A[i] == B[j]) {
                    if(i && j) {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    } else if(i == 0 || j == 0) {
                        dp[i][j] = 1;
                    }
                    if(dp[i][j] > maxlen) {
                        maxlen = dp[i][j];
                    }
                }
            }
        }
        return maxlen;
    }
};
