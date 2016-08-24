class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;
        double result(1);
        bool sign = (n >= 0);
        long nn = labs(n);
        while (nn > 0) {
            if (nn % 2 == 1)
                result *= x;
            x = x * x;
            nn /= 2;
        }
        if (sign == false) return 1.0/result;
        return result;
    }
};
