class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> p(n+1, 10);
        p[0] = 1;
        p[1] = 10;
        int temp(9);
        int base(9);
        
        for(int i = 2;i <= n;i++) {
            temp *= base;
            base --;
            p[i] = p[i-1] + temp;
        }
        
        return p[n];
    }
};
