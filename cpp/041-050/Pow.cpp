class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        double tmp = x;
        bool sign = (n >= 0);
        n = abs(n);
        
        while (n > 0) {
            if (n & 1) {
                res *= tmp;
            }
            tmp *= tmp;
            n = n >> 1;
        }
        
        return sign ? res : 1/res;
    }
};
