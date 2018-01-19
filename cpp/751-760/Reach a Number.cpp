class Solution {
public:
    int reachNumber(int target) {
        target = abs(target);
        int n = 1;
        while (target > 0) {
            target -= n; 
            n++;
        }
        
        if (target %2 == 0) return n - 1;
        if (n % 2 == 1) return n;
        return n + 1;
    }
};
