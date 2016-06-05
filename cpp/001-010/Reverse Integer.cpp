class Solution {
public:
    int reverse(int x) {
        
        long long int y = x;
        if(y < 0) y = -y;
        long long int r(0);
        
        while(y > 0) {
            int remain = y%10;
            r = 10*r + remain;
            y = (y-remain)/10;
        }
        
        if(x < 0) r = -r;
        if(x > 0 && r > INT_MAX) return 0;
        if(x < 0 && r < INT_MIN) return 0;
        return r;
    }
    
};
