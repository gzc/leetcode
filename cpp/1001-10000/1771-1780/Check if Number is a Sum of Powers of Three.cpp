class Solution {
public:
    bool checkPowersOfThree(int n) {
        int tmp = 3;
        while (tmp < n) {
            tmp *= 3;
        }
        
        while (tmp > 0) {
            if (n >= tmp) {
                n -= tmp;
            }
            tmp = tmp/3;
        }
        
        return n == 0;
    }
};
