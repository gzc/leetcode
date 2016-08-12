class Solution {
public:
    double myPow(double x, int n) {
        if(n == 0) return 1;
        double result(1);
        bool sign = (n >= 0);
        n = abs(n);
        while (n > 0) {
            if (n % 2 == 1)
                result *= x;
            x = x * x;
            n /= 2;
        }
        if (sign == false) return 1.0/result;
        return result;
    }
};
