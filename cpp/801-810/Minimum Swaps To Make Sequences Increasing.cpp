class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        // int nswap (no swap), swap
        // if size == 1, at the beginning, it must be true.
        int nswap = 0, swap = 1;
        
        for (int i = 1; i < A.size(); i++) {
            int temp_nswap = INT_MAX, temp_swap = INT_MAX;
            if (A[i] > A[i-1] && B[i] > B[i-1]) {
                temp_nswap = nswap;
                temp_swap = swap + 1;
            }
            
            if (A[i] > B[i-1] && B[i] > A[i-1]) {
                temp_nswap = min(temp_nswap, swap);
                temp_swap = min(temp_swap, nswap + 1);
            }
            
            nswap = temp_nswap;
            swap = temp_swap;
        }
        
        return min(nswap, swap);
    }
};
