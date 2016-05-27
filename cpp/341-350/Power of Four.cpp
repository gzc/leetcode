class Solution {
public:
    bool isPowerOfFour(int num) {
        return ((num-1)&num)==0 && (num-1)%3==0;
    }
};
