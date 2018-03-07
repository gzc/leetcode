class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int count = 0, ans = 0;
        int previous = 0;
        
        for (int i = 0; i < A.size(); i++) {
            if (A[i] >= L && A[i] <= R) {
                count = 1 + i - previous;
                ans += count;
            } else if (A[i] < L) {
                ans += count;
            } else {
                previous = i + 1;
                count = 0;
            }
        }
        
        return ans;
    }
};
