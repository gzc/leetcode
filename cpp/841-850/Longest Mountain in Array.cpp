class Solution {
public:
    int longestMountain(vector<int>& A) {
        int n = A.size();
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);
        
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i-1]) {
                dp1[i] = dp1[i-1]+1;
            } else {
                dp1[i] = 1;
            }
        }
        
        for (int i = n-1; i >= 1; i--) {
            if (A[i-1] > A[i]) {
                dp2[i-1] = dp2[i]+1;
            } else {
                dp2[i-1] = 1;
            }
        }
        
        int ans = 1;
        
        for (int i = 0; i < n; i++) {
            if (dp1[i] > 1 && dp2[i] > 1) {
                ans = max(ans, dp1[i] + dp2[i] - 1);
            }
        }
        
        return ans >= 3 ? ans : 0;
    }
};
