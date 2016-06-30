class Solution {
    
public:
    int getSum(int a, int b) {
        if(a == 0) return b;
        return getSum( (a&b) << 1, a ^ b);
    }
};
