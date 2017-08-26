class Solution {
public:
    string convertToBase7(int num) {
        bool negative = false;
        if (num < 0) {
            negative = true;
            num = -num;
        }
        
        int result = 0;
        
        int base = 1;
        
        while (num > 0) {
            int temp = num % 7;
            num = (num - temp)/7;
            result += base * temp;
            base *= 10;
        }
        
        string resultStr = to_string(result);
        if (negative) resultStr = "-" + resultStr;
        
        return resultStr;
    }
};
