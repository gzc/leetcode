class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& A) {
        if (A.empty()) return A;
        
        // in reverse order, find the first number which is in decreasing trend (we call it violated number here)
        int i(0);
        for (i = A.size()-2; i >= 0; --i)
            if (A[i] > A[i+1]) break;

        if (i == -1) return A;
        
        auto itr = lower_bound(A.begin()+i+1, A.end(), A[i]);
        if (itr != A.begin()) {
            itr--;
            auto copy = itr;
            while (itr != A.begin()) {
                int e1 = *itr;
                itr--;
                int e2 = *itr;
                if (e1 != e2) break;
                copy = itr;
            }
            swap(A[i], *copy);
            return A;
        }
        
        return A;
    }
};
