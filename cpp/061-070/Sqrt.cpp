class Solution {
public:
    int mySqrt(int x) {
        if(x == 0)
            return 0;
        double k = 1.0;             //可任取 
        while(fabs(k*k-x)>=1)     //double不能用==比较 
        { 
            k=(k+x/k)/2; 
        } 
        return k; 
    }
    
    double fabs(double x)
    {
        if(x < 0)
            return -x;
        return x;
    }
};
