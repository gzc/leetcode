class Solution {

    long long mysqrt(long long x) {
        long long i(0), j(x);
        while (i < j) {
            long long mid = (i+j)/2;
            long long v = mid*mid;
            if (v == x) return mid;
            else if(v < x) i = mid + 1;
            else j = mid - 1;
        }
        return i;
    }
    
public:
    bool isPerfectSquare(int num) {
        if (num < 0) return false;
        int v = mysqrt(num);
        if (v*v == num) return true;
        return false;
    }
};
