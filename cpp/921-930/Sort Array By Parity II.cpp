class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i = 0, j = 1;
        for (int k = 0; k < A.size(); k++) {
            if (A[k] % 2 == 0) {
                if (k % 2 == 0) continue;
                swap(A[i], A[k]);
                i += 2;
            } else {
                if (k % 2 == 1) continue;
                swap(A[j], A[k]);
                j += 2;
            }
            k--;
        }
        return A;
    }
};
