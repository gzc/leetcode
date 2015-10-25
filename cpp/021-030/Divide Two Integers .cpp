class Solution {
public:
    int divide(long long dividend, long long divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        long long result(0);
        long long sign(1);
        if(dividend*divisor < 0) sign = -1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        while(dividend >= divisor) {
            long long tmp = divisor;
            long long factor = 1;
            
            while(dividend >= tmp) {
                dividend -= tmp;
                result += factor;
                tmp = tmp << 1;
                factor = factor << 1;
            }
        }
        
        return sign*result;
    }
};