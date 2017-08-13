class Solution {
public:
    int newInteger(int n) {
        int result = 0;
        
        int base = 1;
        
        while (n > 0) {
            int temp = n % 9;
            n = (n - temp)/9;
            result += base * temp;
            base *= 10;
        }
        
        return result;
    }
};
