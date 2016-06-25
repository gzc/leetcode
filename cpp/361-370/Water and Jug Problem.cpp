class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if(x > y) return canMeasureWater(y, x, z);
        if(z == 0) return true;
        int g = gcd(x,y);
        if(z <= (x+y) && z % g == 0) return true;
        return false;
    }
private:
    int gcd(int a, int b){
        return b == 0?a:gcd(b, a%b);
    }
};
