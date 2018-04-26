class Solution {
    
    int maxBit(int num) {
        int ans = 0;
        while(num > 0) {
            num = num >> 1;
            if(ans == 0) ans = 1;
            else ans *= 2;
        }
        return ans;
    }
    
public:
    int rangeBitwiseAnd(int m, int n) {
        if(m == 0) return 0;
        
        int m_maxbit = maxBit(m);
        int n_maxbit = maxBit(n);
        if(m_maxbit != n_maxbit) return 0;
        return m_maxbit + rangeBitwiseAnd(m - m_maxbit, n - n_maxbit);
    }
};
