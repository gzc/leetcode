class Solution {
public:
    int xorOperation(int n, int start) {
        if (n == 1) return start;

        int last = start + 2 * (n - 1);
        
        if (start % 4 <= 1) {
            if (n % 4 == 0) return 0;
            if (n % 4 == 1) return last;
            if (n % 4 == 2) return 2;
            else return 2 ^ last;
        }
        
        return start ^ xorOperation(n-1, start + 2);
    }
};
