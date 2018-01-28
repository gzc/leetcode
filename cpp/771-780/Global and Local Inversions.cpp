class Solution {
    
public:
    bool isIdealPermutation(vector<int>& A) {
        vector<int> dp(A.size(), 0);
        dp[0] = A[0];
        for (int i = 1; i < A.size(); i++) {
            dp[i] = max(dp[i-1], A[i]);
        }
        
        for (int i = 2; i < A.size(); i++) {
            if (A[i] < dp[i-2]) {
                return false;
            }
        }
        
        return true;
    }
};
