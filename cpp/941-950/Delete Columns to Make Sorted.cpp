class Solution {
public:
    int minDeletionSize(vector<string>& A) {
        int res = 0;
        if (A.empty()) return res;
        for (int c = 0; c < A[0].size(); ++c)
            for (int i = 1; i < A.size(); ++i) {
                if (A[i - 1][c] > A[i][c]) {
                    ++res;
                    break;
                }
            }
        return res;
    }
};
