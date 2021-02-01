class Solution {
public:
    int minimumBoxes(int n) {
        int ans = 0;
        int tmp = 0;
        
        for (int i = 1;;i++) {
            
            tmp += i;
            
            if (n <= tmp) {
                int k = 1;
                while (n > 0) {
                    n -= k;
                    ans++;
                    k++;
                }
                break;
            }
            
            n -= tmp;
            ans += i;
        }
        
        return ans;
    }
};
