class Solution {
public:
    int myAtoi(string str) {
        while (str[0] == ' ') {
            str.erase(0, 1);
        }
        
        int sign = 1;
        if (str[0] == '+' || str[0] == '-') {
            if (str[0] == '-') sign = -1;
            str.erase(0, 1);
        }
        
        int result = 0;
        for (int i = 0; i < str.length(); i++) {
            if (!isdigit(str[i])) {
                break;
            }
            int v = str[i] - '0';

            if (result > INT_MAX/10) {
                if (sign == 1) return INT_MAX;
                if (sign == -1) return INT_MIN;
            } else if (result == INT_MAX/10) {
                if (sign == 1 && v >= 7) return INT_MAX;
                if (sign == -1 && v >= 8) return INT_MIN;
            }
            result = 10 * result + v;
        }
        
        return result * sign;
    }
};
