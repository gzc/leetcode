class Solution {
public:
    int divide(long long dividend, long long divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        long long result(0), sign(1);
        if (dividend > 0 && divisor < 0) sign = -1;
        if (dividend < 0 && divisor > 0) sign = -1;
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        long long arrays[35] = {0};
        arrays[0] = divisor;
        int index = 0;
        while (arrays[index] < dividend) {
            arrays[index+1] = arrays[index] + arrays[index];
            index++;
        }
        
        while (index >= 0) {
            if (dividend >= arrays[index]) {
                result += (1 << index);
                dividend -= arrays[index];
            }
            index--;
        }
        
        return sign*result;
    }
};
