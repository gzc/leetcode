#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Solution {
public:
    int divide(long long dividend, long long divisor) {
        
        if(dividend > 0 && divisor > 0 && dividend < divisor) return 0;
        if(dividend < 0 && divisor < 0 && dividend > divisor) return 0;
        
        int sign(1);
        if(dividend > 0 && divisor < 0) sign = -1;
        else if(dividend < 0 && divisor > 0)sign = -1;
        
        dividend = abs(dividend);
        divisor = abs(divisor);
        
        long long r(0), times(1);
        
        while( (dividend >> 1) >= divisor)
        {
            times = times << 1;
            divisor = divisor << 1;
        }
        
        while(times > 0)
        {
            if(dividend >= divisor)
            {
                r += times;
                dividend -= divisor;
            }
            times /= 2;
            divisor /= 2;
        }
        r = r * sign;
        
        if(r > INT_MAX || r < INT_MIN) return INT_MAX;
        
        return r;
    }
    
};

int main()
{
    Solution s;

    cout << s.divide(INT_MIN, 1);
    
    return 0;
}