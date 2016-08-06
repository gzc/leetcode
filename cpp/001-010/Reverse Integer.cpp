class Solution {
public:
    int reverse(int x) {
        long long int y(x), reversed_value(0);
        if (y < 0) y = -y;
        
        while (y > 0) {
            int remain = y%10;
            reversed_value = 10*reversed_value + remain;
            y = (y-remain)/10;
        }
        
        if (x < 0) reversed_value = -reversed_value;
        if (x > 0 && reversed_value > INT_MAX) return 0;
        if (x < 0 && reversed_value < INT_MIN) return 0;
        return reversed_value;
    }
};
