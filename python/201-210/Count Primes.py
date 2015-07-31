import math

class Solution:
    # @param {integer} n
    # @return {integer}
    def countPrimes(self, n):
        if n <= 2:
            return 0
        c = int(math.sqrt(n))
        b = [False] * n;
        
        for i in range(3, c+1):
            if not b[i]:
                j = i*i
                k = i << 1
                while j < n:
                    b[j] = True
                    j += k
        
        res = 1
        for i in range(3, n, 2):
            if not b[i]:
                res += 1
        return res