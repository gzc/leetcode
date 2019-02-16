class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        vector<int> ans(A.size());
        int i = 0, j = A.size() - 1;
        int k = 0;
        while (i <= j) {
            if (abs(A[i]) >= abs(A[j])) {
                ans[k] = A[i]*A[i];
                i++;
            } else {
                ans[k] = A[j]*A[j];
                j--;
            }
            k++;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
