class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        int n = A.size(), pmax = 0;
        vector<int> B(n);
        B[n - 1] = A[n - 1];
        for (int i = n - 2; i > 0; --i)
            B[i] = min(A[i], B[i + 1]);
        for (int i = 1; i < n; ++i) {
            pmax = max(pmax, A[i - 1]);
            if (pmax <= B[i]) return i;
        }
    }
};
