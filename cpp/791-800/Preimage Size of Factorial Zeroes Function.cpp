class Solution {
    
public:
    int preimageSizeFZF(long K) {
        long a = 1;
        while (K >= 5*a + 1) a = 5*a + 1;
        cout << a << endl;
        while (K >= 6) {
            if (K % a == 0) {
                if (K == 5*a) {
                    return 0;
                } else {
                    return 5;
                }
            }
            K = K % a;
            a = (a-1)/5;
        }
        
        if (K == 5) return 0;
        return 5;
    }
};

// 1 1 1 1 2 1 1 1 1 2 1 1 1 1 2 1 1 1 1 2 1 1 1 1 3 
// 12 30
