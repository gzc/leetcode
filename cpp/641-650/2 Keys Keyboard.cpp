class Solution {
public:
    int minSteps(int n) {
        if (n == 1) return 0;
        if (n == 2) return 2;
        if (n == 3) return 3;
        
        for (int i = 2; i <= n; i++) {
            if (n % i != 0) continue;
            int temp = n / i;
            if (temp < i) return n;
            if (temp * i == n) {
                return i + minSteps(temp);
            }
        }
        
        return n;
    }
};
