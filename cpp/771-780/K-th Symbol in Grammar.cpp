class Solution {
public:
    int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        if (N == 2) {
            if (K == 1) return 0;
            return 1;
        }
        int temp = kthGrammar(N-1, (K+1)/2);
        if (K % 2 == 1) return temp;
        return (temp+1)%2;
    }
};
