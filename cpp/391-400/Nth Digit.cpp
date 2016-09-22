class Solution {
    
    int process(long long num, long long n) {
        int digit = (n-1)/num;
        int base = 1;
        for (int i = 1;i < num;i++) base *= 10;
        base += digit;
        return to_string(base)[(n-1)%num] - '0';
    }
    
public:
    int findNthDigit(int n) {
        long long temp = 9, num = 1;
        while (true) {
            if (n - temp*num <= 0) break;
            n = n - temp*num;
            temp *= 10;
            num++;
        }
        return process(num, n);
    }
};
