class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& A, int K) {
        vector<int> dp(A.size()+1, 0);
        
        for (int i = 0; i < A.size(); i++) {
            int p_i = max(-1, i - K);
            int maximum_i_sum = 0;
            int temp_max = -1;
            int n_elements = 0;
            for (int j = i; j > p_i; j--) {
                n_elements++;
                temp_max = max(temp_max, A[j]);
                maximum_i_sum = max(maximum_i_sum, dp[j] + n_elements * temp_max);
            }
            
            dp[i+1] = maximum_i_sum;
        } 
        
        return dp.back();
    }
};
