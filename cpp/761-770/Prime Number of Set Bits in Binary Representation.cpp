class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        set<int> primes = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
        int cnt = 0;
        for (int i = L; i <= R; i++) {
            int bits = 0;
            for (int n = i; n; n >>= 1)
                bits += n & 1;
            cnt += primes.count(bits);
        }
        return cnt;
    }
};
