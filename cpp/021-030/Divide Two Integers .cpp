/*
 * Solution 1:
 * Use long type
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            sign = -1;
        }

        long new_dividend = abs((long)dividend);
        long new_divisor = abs((long)divisor);
        long result = 0;

        int power = 0;
        while (new_divisor <= new_dividend / 2) {
            new_divisor *= 2;
            power++;
        }
        
        while (power >= 0) {
            if (new_dividend >= new_divisor) {
                result += (1 << power);
                new_dividend -= new_divisor;
            }
            power--;
            new_divisor /= 2;
        }
        
        return (long)sign * result;
    }
};

/*
 * Solution 2:
 * Don't use long type
 */
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN) {
            if (divisor == -1) {
                return INT_MAX;
            } 
            if (divisor > 0) {
                return -1 + divide(dividend+divisor, divisor);
            } else {
                return 1 + divide(dividend-divisor, divisor);
            }
        }
        if (divisor == INT_MIN) {
            return dividend == INT_MIN ? 1 : 0;
        }
        int sign = 1;
        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            sign = -1;
        }

        int new_dividend = abs(dividend);
        int new_divisor = abs(divisor);
        int result = 0;

        int power = 0;
        while (new_divisor <= new_dividend / 2) {
            new_divisor *= 2;
            power++;
        }
        
        while (power >= 0) {
            if (new_dividend >= new_divisor) {
                result += (1 << power);
                new_dividend -= new_divisor;
            }
            power--;
            new_divisor /= 2;
        }
        
        return sign * result;
    }
};
