class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for (auto i = 0; i < A.size() - 2; ++i) {
            if (A[i] == A[i + 1] || A[i] == A[i + 2]) {
                return A[i];
            }
        }
        return A[A.size() - 1]; 
    }
};
