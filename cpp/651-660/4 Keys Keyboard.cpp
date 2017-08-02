class Solution {
    
public:
    int maxA(int N) {
        if (N <= 6) return N;
        return max(3*maxA(N - 4), 4*maxA(N-5));
    }
};
