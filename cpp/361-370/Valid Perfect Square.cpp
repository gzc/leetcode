class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1;
        int j = num;
        
        while (i <= j) {
            int mid = i + (j - i) / 2;
            
            if ((long)mid * (long)mid == (long)num) return true;
            
            if ((long)mid * (long)mid > (long)num) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }
        
        return false;
    }
};
