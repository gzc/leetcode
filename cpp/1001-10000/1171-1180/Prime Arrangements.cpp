class Solution {
    
    bool isPrime(int k) {
        if (k == 1) return false;
        if (k <= 3) return true;
        int limit = sqrt(k);
        for (int i = 2; i <= limit; i++) {
            if (k % i == 0) return false;
        }
        return true;
    }
    
public:
    int numPrimeArrangements(int n) {
        int pn = 0;
        for (int i = 1; i <= n; i++) {
            if (isPrime(i)) {
                pn++;
            }
        }
        int npn = n - pn;
        
        long ans = 1;
        int mod = 1000000007;
        
        for (int i = 1; i <= pn; i++) {
            ans = (ans * i) % mod;
        }
        for (int i = 1; i <= npn; i++) {
            ans = (ans * i) % mod;
        }
        return ans;
    }
};
