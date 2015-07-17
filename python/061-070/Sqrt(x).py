class Solution:
    # @param {integer} x
    # @return {integer}
    def mySqrt(self, x):
        if x == 0:
            return 0
        k = 1.0
        while abs(k*k-x) >= 1:
            k = (k+x/k)/2
        return int(k)