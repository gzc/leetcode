class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(begin(A), end(A));
        int i = 0, j = A.size() - 1;
        int ans = -1;
        
        while (i < j) {
            int sum = A[i] + A[j];
            if (sum < K) {
                ans = max(ans, sum);
                i++;
            } else {
                j--;
            }
        }
        
        return ans;
    }
};
